--- daemon/filters/fsmapfilter.go.orig
+++ daemon/filters/fsmapfilter.go
@@ -2,6 +2,7 @@ package filters
 
 import (
 	"fmt"
+	"path/filepath"
 	"strings"
 
 	"github.com/pkg/errors"
@@ -24,6 +25,19 @@ type datasetMapFilterEntry struct {
 	// we have to convert it to the desired rep dynamically
 	mapping      string
 	subtreeMatch bool
+
+	// subtreePattern contains a shell pattern for checking is a subtree matching
+	// this definition or not. See pattern syntax in [filepath.Match].
+	subtreePattern string
+}
+
+func (e datasetMapFilterEntry) HasPattern() bool {
+	return e.subtreePattern != ""
+}
+
+func (e datasetMapFilterEntry) Match(path *zfs.DatasetPath) (bool, error) {
+	fullPattern := filepath.Join(e.path.ToString(), e.subtreePattern)
+	return filepath.Match(fullPattern, path.ToString())
 }
 
 func NewDatasetMapFilter(capacity int, filterMode bool) *DatasetMapFilter {
@@ -43,28 +57,33 @@ func (m *DatasetMapFilter) Add(pathPattern, mapping string) (err error) {
 
 	// assert path glob adheres to spec
 	const SUBTREE_PATTERN string = "<"
-	patternCount := strings.Count(pathPattern, SUBTREE_PATTERN)
-	switch {
-	case patternCount > 1:
-	case patternCount == 1 && !strings.HasSuffix(pathPattern, SUBTREE_PATTERN):
-		err = fmt.Errorf("pattern invalid: only one '<' at end of string allowed")
-		return
+	pathStr, pattern, found := strings.Cut(pathPattern, SUBTREE_PATTERN)
+
+	if pattern != "" {
+		if strings.Contains(pattern, SUBTREE_PATTERN) {
+			return fmt.Errorf(
+				"invalid shell pattern %q in path pattern %q: '<' not allowed in shell patterns",
+				pattern, pathPattern)
+		}
+		if _, err := filepath.Match(pattern, ""); err != nil {
+			return fmt.Errorf(
+				"invalid shell pattern %q in %q: %w", pattern, pathPattern, err)
+		}
 	}
 
-	pathStr := strings.TrimSuffix(pathPattern, SUBTREE_PATTERN)
 	path, err := zfs.NewDatasetPath(pathStr)
 	if err != nil {
 		return fmt.Errorf("pattern is not a dataset path: %s", err)
 	}
 
 	entry := datasetMapFilterEntry{
-		path:         path,
-		mapping:      mapping,
-		subtreeMatch: patternCount > 0,
+		path:           path,
+		mapping:        mapping,
+		subtreeMatch:   found,
+		subtreePattern: pattern,
 	}
 	m.entries = append(m.entries, entry)
 	return
-
 }
 
 // find the most specific prefix mapping we have
@@ -155,9 +174,17 @@ func (m DatasetMapFilter) Filter(p *zfs.DatasetPath) (pass bool, err error) {
 		pass = false
 		return
 	}
+
 	me := m.entries[mi]
-	pass, err = m.parseDatasetFilterResult(me.mapping)
-	return
+	if me.HasPattern() {
+		if matched, err := me.Match(p); err != nil {
+			return false, err
+		} else if !matched {
+			return false, nil
+		}
+	}
+
+	return m.parseDatasetFilterResult(me.mapping)
 }
 
 func (m DatasetMapFilter) UserSpecifiedDatasets() (datasets zfs.UserSpecifiedDatasetsSet) {

diff --git a/pruning/keep_last_n.go b/pruning/keep_last_n.go
index 023568d..73f00cc 100644
--- a/pruning/keep_last_n.go
+++ b/pruning/keep_last_n.go
@@ -33,11 +33,6 @@ func NewKeepLastN(n int, regex string) (*KeepLastN, error) {
 }
 
 func (k KeepLastN) KeepRule(snaps []Snapshot) (destroyList []Snapshot) {
-
-	if k.n > len(snaps) {
-		return []Snapshot{}
-	}
-
 	matching, notMatching := partitionSnapList(snaps, func(snapshot Snapshot) bool {
 		return k.re.MatchString(snapshot.Name())
 	})

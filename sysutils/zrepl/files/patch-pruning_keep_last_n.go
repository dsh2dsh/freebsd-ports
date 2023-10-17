--- pruning/keep_last_n.go.orig	2023-10-17 21:21:53.846062000 +0200
+++ pruning/keep_last_n.go	2023-10-17 20:59:28.901736000 +0200
@@ -33,11 +33,6 @@
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

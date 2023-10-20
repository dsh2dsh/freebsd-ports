--- daemon/job/build_jobs.go.orig	2023-10-18 20:01:43.176388000 +0200
+++ daemon/job/build_jobs.go	2023-10-18 19:56:19.522028000 +0200
@@ -77,7 +77,6 @@
 		panic(fmt.Sprintf("implementation error: unknown job type %T", v))
 	}
 	return j, nil
-
 }
 
 func validateReceivingSidesDoNotOverlap(receivingRootFSs []string) error {
@@ -102,7 +101,7 @@
 	// thus,
 	// if any i is prefix of i+n (n >= 1), there is overlap
 	for i := 0; i < len(rfss)-1; i++ {
-		if strings.HasPrefix(rfss[i+1], rfss[i]) {
+		if rfss[i] != rfss[i+1] && strings.HasPrefix(rfss[i+1], rfss[i]) {
 			return fmt.Errorf("receiving jobs with overlapping root filesystems are forbidden")
 		}
 	}

--- src/cmd/go/internal/modload/vendor.go.orig	2024-02-10 22:04:57.320671000 +0100
+++ src/cmd/go/internal/modload/vendor.go	2024-02-10 22:14:29.877568000 +0100
@@ -159,7 +159,7 @@
 			panic(fmt.Errorf("not in workspace mode but number of indexes is %v, not 1", len(indexes)))
 		}
 		index := indexes[0]
-		if gover.Compare(index.goVersion, "1.14") < 0 {
+		if gover.Compare(index.goVersion, "1.14") < 0 || os.Getenv("GO_NO_VENDOR_CHECKS") == "1" {
 			// Go versions before 1.14 did not include enough information in
 			// vendor/modules.txt to check for consistency.
 			// If we know that we're on an earlier version, relax the consistency check.

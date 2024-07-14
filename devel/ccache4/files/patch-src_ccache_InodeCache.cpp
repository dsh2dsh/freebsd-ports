--- src/ccache/InodeCache.cpp.orig	2024-06-30 20:46:01.000000000 +0200
+++ src/ccache/InodeCache.cpp	2024-07-14 18:43:55.450203000 +0200
@@ -139,6 +139,7 @@
       "ufs",
       "xfs",
       "zfs",
+      "nullfs",
     };
     if (std::find(known_to_work_filesystems.begin(),
                   known_to_work_filesystems.end(),

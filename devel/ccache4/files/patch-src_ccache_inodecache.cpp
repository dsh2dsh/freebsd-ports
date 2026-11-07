--- src/ccache/inodecache.cpp.orig	2025-03-09 15:17:52 UTC
+++ src/ccache/inodecache.cpp
@@ -140,6 +140,7 @@ fd_is_on_known_to_work_file_system(int fd)
       "ufs",
       "xfs",
       "zfs",
+      "nullfs",
     };
     if (std::find(known_to_work_filesystems.begin(),
                   known_to_work_filesystems.end(),

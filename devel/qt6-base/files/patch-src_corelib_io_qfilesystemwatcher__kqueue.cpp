--- src/corelib/io/qfilesystemwatcher_kqueue.cpp.orig	2024-11-14 11:02:40 UTC
+++ src/corelib/io/qfilesystemwatcher_kqueue.cpp
@@ -69,7 +69,8 @@ QStringList QKqueueFileSystemWatcherEngine::addPaths(c
         fd = qt_safe_open(QFile::encodeName(path), O_RDONLY);
 #endif
         if (fd == -1) {
-            perror("QKqueueFileSystemWatcherEngine::addPaths: open");
+            if (errno != ENOENT)
+                perror("QKqueueFileSystemWatcherEngine::addPaths: open");
             continue;
         }
         if (fd >= (int)FD_SETSIZE / 2 && fd < (int)FD_SETSIZE) {

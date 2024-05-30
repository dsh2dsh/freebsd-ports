--- cmake/FindFmt.cmake.orig	2024-05-30 16:46:34.083462000 +0200
+++ cmake/FindFmt.cmake	2024-05-30 22:32:18.291712000 +0200
@@ -30,7 +30,7 @@
       message(STATUS "Downloading Fmt from the internet since Fmt>=${Fmt_FIND_VERSION} was not found locally and DEPS=AUTO")
       set(_download_fmt TRUE)
     else()
-      message(FATAL_ERROR "Could not find Fmt>=${Fmt_FIND_VERSION}")
+      message(STATUS "Using bundled Fmt since Fmt>=${Fmt_FIND_VERSION} was not found locally")
     endif()
   endif()
 endif()

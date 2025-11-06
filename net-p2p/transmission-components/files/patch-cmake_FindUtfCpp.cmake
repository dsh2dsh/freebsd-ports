--- cmake/FindUtfCpp.cmake.orig	2025-11-05 23:57:39 UTC
+++ cmake/FindUtfCpp.cmake
@@ -2,4 +2,4 @@ target_include_directories(utf8::cpp
 
 target_include_directories(utf8::cpp
     INTERFACE
-        ${TR_THIRD_PARTY_SOURCE_DIR}/utfcpp/source)
+    	${CMAKE_INSTALL_PREFIX}/include/utf8cpp)

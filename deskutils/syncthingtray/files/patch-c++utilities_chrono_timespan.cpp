--- ./../c++utilities/chrono/timespan.cpp.orig	2023-12-17 16:08:04.427911000 +0100
+++ ./../c++utilities/chrono/timespan.cpp	2023-12-17 16:08:21.333354000 +0100
@@ -5,6 +5,7 @@
 #include "../conversion/stringbuilder.h"
 #include "../conversion/stringconversion.h"
 
+#include <array>
 #include <charconv>
 #include <cmath>
 #include <cstdlib>

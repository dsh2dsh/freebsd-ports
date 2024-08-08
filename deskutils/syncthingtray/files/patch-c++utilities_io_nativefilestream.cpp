--- c++utilities/io/nativefilestream.cpp.orig	2024-08-04 16:08:48 UTC
+++ c++utilities/io/nativefilestream.cpp
@@ -196,7 +196,7 @@ NativeFileStream::FileBuffer::FileBuffer(const char *p
     buffer = make_unique<StreamBuffer>(handle, boost::iostreams::close_handle);
     // if we wanted to open assign the descriptor as well: descriptor = _open_osfhandle(reinterpret_cast<intptr_t>(handle), nativeParams.flags);
 #else
-    descriptor = ::open(path.data(), nativeParams.openFlags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
+    descriptor = ::open(path, nativeParams.openFlags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
     if (descriptor == -1) {
         throw std::ios_base::failure("open failed", std::error_code(errno, std::system_category()));
     }

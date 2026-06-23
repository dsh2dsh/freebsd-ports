--- fmap.c.orig	2026-06-23 13:59:57 UTC
+++ fmap.c
@@ -197,7 +197,7 @@ fmap_open(const char *path, int fd, off_t sz)
 	 * we force bufio to run a sliding window since we can't map the whole
 	 * file.
 	 */
-	if (sz > (off_t)SIZE_MAX)
+	if ((uintmax_t)sz > SIZE_MAX)
 		fm->ftype = FT_BUFIO;
 	else
 		fm->ftype = fmap_env_type();
@@ -357,7 +357,7 @@ fmap_access_valid(struct fmap *fm, off_t offset, size_
 	assert(fm->ftype != FT_NULL);
 	switch (fm->ftype) {
 	case FT_MMAP:
-		return offset + (off_t)datasz <= fm->mapsz;
+		return (size_t)offset + datasz <= (size_t)fm->mapsz;
 	case FT_BUFIO:
 		/*
 		 * For bufio mappings, we don't actually know if the access will

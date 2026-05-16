--- a/lib/sysxattrs.c.orig	2025-08-23 09:31:28.000000000 +0200
+++ b/lib/sysxattrs.c	2026-05-16 17:29:21.191872000 +0200
@@ -142,15 +142,12 @@
 	 * terminator.  We need to change this into a series of null-terminted
 	 * strings.  Since the size is the same, we can simply transform the
 	 * output in place. */
-	for (off = 0; off < len; off += keylen + 1) {
-		keylen = ((unsigned char*)list)[off];
-		if (off + keylen >= len) {
-			/* Should be impossible, but bugs happen! */
-			errno = EINVAL;
-			return -1;
-		}
-		memmove(list+off, list+off+1, keylen);
-		list[off+keylen] = '\0';
+	keylen = (unsigned char)list[0];
+	memmove(list, list+1, len-1);
+	list[len-1] = '\0';
+	for (off = keylen; off < (len - 1); off += (keylen + 1)) {
+		keylen = (unsigned char)list[off];
+		list[off] = '\0';
 	}
 
 	return len;

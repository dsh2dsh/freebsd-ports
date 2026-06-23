--- sender.c.orig	2026-02-26 04:17:33 UTC
+++ sender.c
@@ -213,7 +213,8 @@ token_ff_compressed(struct sess *sess, struct send_up 
 	assert(up->stat.map != NULL);
 
 	off = up->stat.curpos;
-	assert(sz == up->cur->blks->len || (off_t)sz == up->stat.mapsz - off);
+	assert(sz == up->cur->blks->len ||
+	    sz == (size_t)(up->stat.mapsz - off));
 
 	if (!fmap_trap(up->stat.map)) {
 		sess->total_errors++;

--- rules.c.orig	2026-06-23 14:16:03 UTC
+++ rules.c
@@ -108,7 +108,7 @@ static const char builtin_cvsignore[] =
 	"_$* *$ *.old *.bak *.BAK *.orig *.rej .del-* "
 	"*.a *.olb *.o *.obj *.so *.exe *.Z *.elc "
 	"*.ln core "
-	".svn/ ";
+	".svn/ .git/ .hg/ .bzr/ ";
 
 static char		 rule_base[MAXPATHLEN];
 static char		*rule_base_cwdend;

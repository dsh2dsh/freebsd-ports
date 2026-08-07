--- plugins-scripts/check_ircd.pl.orig	2026-08-07 13:17:02 UTC
+++ plugins-scripts/check_ircd.pl
@@ -65,6 +65,7 @@ $ENV{'ENV'}='';
 $ENV{'PATH'}='@TRUSTED_PATH@';
 $ENV{'BASH_ENV'}=''; 
 $ENV{'ENV'}='';
+$ENV{CDPATH} = "";
 
 # -----------------------------------------------------------------[ Global ]--
 

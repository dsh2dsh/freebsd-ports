--- plugins/check_nagios.c.orig	2026-08-07 13:17:02 UTC
+++ plugins/check_nagios.c
@@ -118,6 +118,7 @@ int main(int argc, char **argv) {
 	int procuid = 0;
 	int procpid = 0;
 	int procppid = 0;
+	int procjid = 0;
 	int procvsz = 0;
 	int procrss = 0;
 	int proc_entries = 0;

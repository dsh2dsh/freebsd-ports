--- shell/completion.bash.orig	2023-06-14 17:37:41.000000000 +0200
+++ shell/completion.bash	2023-08-13 18:23:31.794179000 +0200
@@ -271,8 +271,7 @@
 
 _fzf_proc_completion() {
   _fzf_complete -m --header-lines=1 --preview 'echo {}' --preview-window down:3:wrap --min-height 15 -- "$@" < <(
-    command ps -eo user,pid,ppid,start,time,command 2> /dev/null ||
-      command ps -eo user,pid,ppid,time,args # For BusyBox
+    command ps -fux 2> /dev/null
   )
 }
 

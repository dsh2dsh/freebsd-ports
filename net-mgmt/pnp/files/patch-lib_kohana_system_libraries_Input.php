--- lib/kohana/system/libraries/Input.php.orig	2021-03-02 12:05:17.257818000 +0200
+++ lib/kohana/system/libraries/Input.php	2021-03-02 12:05:38.005038000 +0200
@@ -53,20 +53,6 @@
 
 		if (Input::$instance === NULL)
 		{
-			// magic_quotes_runtime is enabled
-			if (get_magic_quotes_runtime())
-			{
-				set_magic_quotes_runtime(0);
-				Kohana::log('debug', 'Disable magic_quotes_runtime! It is evil and deprecated: http://php.net/magic_quotes');
-			}
-
-			// magic_quotes_gpc is enabled
-			if (get_magic_quotes_gpc())
-			{
-				$this->magic_quotes_gpc = TRUE;
-				Kohana::log('debug', 'Disable magic_quotes_gpc! It is evil and deprecated: http://php.net/magic_quotes');
-			}
-
 			// register_globals is enabled
 			if (ini_get('register_globals'))
 			{

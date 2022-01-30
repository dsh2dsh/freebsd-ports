--- lib/kohana/system/libraries/Input.php.orig	2017-08-21 17:52:37.000000000 +0200
+++ lib/kohana/system/libraries/Input.php	2022-01-30 15:23:47.822335000 +0100
@@ -54,14 +54,14 @@
 		if (Input::$instance === NULL)
 		{
 			// magic_quotes_runtime is enabled
-			if (get_magic_quotes_runtime())
+			if (function_exists('get_magic_quotes_runtime'))
 			{
-				set_magic_quotes_runtime(0);
+				ini_set('magic_quotes_runtime', 0);
 				Kohana::log('debug', 'Disable magic_quotes_runtime! It is evil and deprecated: http://php.net/magic_quotes');
 			}
 
 			// magic_quotes_gpc is enabled
-			if (get_magic_quotes_gpc())
+			if (function_exists('get_magic_quotes_runtime'))
 			{
 				$this->magic_quotes_gpc = TRUE;
 				Kohana::log('debug', 'Disable magic_quotes_gpc! It is evil and deprecated: http://php.net/magic_quotes');

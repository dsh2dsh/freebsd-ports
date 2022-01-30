--- lib/kohana/system/core/Kohana.php.orig	2022-01-30 15:29:15.290587000 +0100
+++ lib/kohana/system/core/Kohana.php	2022-01-30 15:46:15.706460000 +0100
@@ -858,7 +858,7 @@
 		try
 		{
 			// PHP errors have 5 args, always
-			$PHP_ERROR = (func_num_args() === 5);
+			$PHP_ERROR = (func_num_args() === 4);
 	
 			// Test to see if errors should be displayed
 			if ($PHP_ERROR AND (error_reporting() & $exception) === 0)

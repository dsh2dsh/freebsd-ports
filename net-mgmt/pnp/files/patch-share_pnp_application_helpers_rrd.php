--- share/pnp/application/helpers/rrd.php.orig	2022-01-30 15:29:15.274984000 +0100
+++ share/pnp/application/helpers/rrd.php	2022-01-30 15:56:32.330749000 +0100
@@ -207,7 +207,7 @@
         if(is_array($cf)){
             foreach($cf as $key => $val){
                 $line .= sprintf("GPRINT:%s:%s:",$vname,$val);
-                if($key == sizeof($cf)-1){
+                if($key == count($cf)-1){
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'\\l" ';
                 }else{
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'" ';
@@ -234,7 +234,7 @@
         if(is_array($cf)){
             foreach($cf as $key => $val){
                 $line .= sprintf("GPRINT:%s:%s:",$vname,$val);
-                if(($key == sizeof($cf)-1)and($align != "")){
+                if(($key == count($cf)-1)and($align != "")){
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).$align.'" ';
                 }else{
                     $line .= '"'.$text.' '.ucfirst(strtolower($val)).'" ';
@@ -325,7 +325,7 @@
     }
 
 
-	public static function alerter($vname=FALSE, $label=FALSE, $warning=FALSE, $critical=FALSE, $opacity = 'ff', $unit, $color_green = '#00ff00', $color_btw   = '#ffff00', $color_red   = '#ff0000', $line_col = '#0000ff') {
+	public static function alerter($vname, $label, $warning, $critical, $opacity', $unit, $color_green = '#00ff00', $color_btw   = '#ffff00', $color_red   = '#ff0000', $line_col = '#0000ff') {
 	
 		if($vname === FALSE){
 			throw new Kohana_exception("rrd::". __FUNCTION__ . "() First Parameter 'vname' is missing");
@@ -363,7 +363,7 @@
 	    return $line;
     }
 
-    public static function alerter_gr($vname=FALSE,$label=FALSE,$warning=FALSE,$critical=FALSE,$opacity='ff',$unit,$color_green='#00ff00',$color_btw='#ffff00',$color_red='#ff0000',$line_col='#0000ff',$start_color="#ffffff") {
+    public static function alerter_gr($vname,$label,$warning,$critical,$opacity',$unit,$color_green='#00ff00',$color_btw='#ffff00',$color_red='#ff0000',$line_col='#0000ff',$start_color="#ffffff") {
 
         if($vname === FALSE){
             throw new Kohana_exception("rrd::". __FUNCTION__ . "() First Parameter 'vname' is missing");

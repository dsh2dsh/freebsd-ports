--- share/pnp/application/models/data.php.orig	2022-01-30 15:29:15.274687000 +0100
+++ share/pnp/application/models/data.php	2022-01-30 15:29:36.944013000 +0100
@@ -45,11 +45,11 @@
                 }
             }
         }
-        if(sizeof($templates) > 0){
+        if(empty($templates)){
+            return FALSE;
+        }else{
             sort($templates);
             return $templates;
-        }else{
-            return FALSE;
         }
     }
 
@@ -97,7 +97,9 @@
                     throw new Kohana_User_Exception('Perfdata Dir', "Can not open $path");
                }
            }
-        if(sizeof($hosts)>0){
+        if(empty($hosts)){
+            throw new Kohana_Exception('error.perfdata-dir-empty', $conf['rrdbase'] );
+        }else{
             # Obtain a list of columns
             foreach ($hosts as $key => $row) {
                 $sort[$key]  = $row['sort'];
@@ -105,8 +107,6 @@
             # Sort the data with volume descending, edition ascending
             # Add $data as the last parameter, to sort by the common key
             array_multisort($sort, SORT_ASC, $hosts);
-        }else{
-            throw new Kohana_Exception('error.perfdata-dir-empty', $conf['rrdbase'] );
         }
         return $hosts;
     }
@@ -147,7 +147,7 @@
         }else{
             throw new Kohana_Exception('error.perfdata-dir-for-host', $path, $hostname );
         }
-        if( is_array($services) && sizeof($services) > 0){
+        if( is_array($services) && (!empty($services))){
             # Obtain a list of columns
             foreach ($services as $key => $row) {
                 $sort[$key]  = $row['name'];
@@ -205,7 +205,7 @@
             $i++;
         }
         #print Kohana::debug($services);
-        if( is_array($services) && sizeof($services) > 0){
+        if( is_array($services) && (!empty($services))){
             # Obtain a list of columns
             foreach ($services as $key => $row) {
                 $sort[$key]  = $row['sort'];
@@ -214,7 +214,7 @@
             # Add $data as the last parameter, to sort by the common key
             array_multisort($sort, SORT_STRING, $services);
         }        
-        if(is_array($host) && sizeof($host) > 0 ){
+        if(is_array($host) && (!empty($host))){
             array_unshift($services, $host[0]);
         }
         return $services;
@@ -232,7 +232,7 @@
                 break;
             }
         }
-        if(sizeof($srv) == 0){
+        if(empty($srv)){
             throw new Kohana_Exception('error.get-first-service', $hostname );
         }
         return $srv['name'];
@@ -250,7 +250,7 @@
                 break;
             }
         }
-        if(sizeof($host) == 0){
+        if(empty($host)){
             throw new Kohana_Exception('error.get-first-host');
         }
         return $host['name'];
@@ -266,7 +266,7 @@
         $xml         = array();
         if (file_exists($xmlfile)) {
             libxml_use_internal_errors(TRUE);
-            libxml_clear_errors(TRUE);
+            libxml_clear_errors();
             if(! $xml = simplexml_load_file($xmlfile) ){;
                 if( $throw_exception == TRUE ){
                     $errors = '<br>';
@@ -693,7 +693,7 @@
         }
         
            $view=intval( pnp::clean($view) );
-           if($view >= sizeof($this->config->views)){
+           if($view >= count($this->config->views)){
                $view = 1;
            }
 
@@ -735,7 +735,7 @@
            $timerange['f_end']   = date($this->config->conf['date_fmt'],$end);
            $timerange['cmd']     = " --start $start --end $end ";
            $timerange['type']    = "views";
-           for ($i = 0; $i < sizeof($this->config->views); $i++) {
+           for ($i = 0; $i < count($this->config->views); $i++) {
                $timerange[$i]['title']   = $this->config->views[$i]['title'];
                $timerange[$i]['start']   = $end - $this->config->views[$i]['start'];
                $timerange[$i]['f_start'] = date($this->config->conf['date_fmt'],$end - $this->config->views[$i]['start']);
@@ -747,7 +747,7 @@
     }
 
     public function buildBasketStruct($basket,$view = NULL){
-        if(is_array($basket) && sizeof($basket) > 0){
+        if(is_array($basket) && (!empty($basket))){
 	    if($view == ""){
                  $views = array_keys($this->config->views);
             }else{
@@ -757,9 +757,9 @@
                 foreach($basket as $item){
                     # explode host::service::source
                     $slices = explode("::",$item);
-                    if(sizeof($slices) == 2)
+                    if(count($slices) == 2)
                         $this->buildDataStruct($slices[0], $slices[1], $view);
-                    if(sizeof($slices) == 3)
+                    if(count($slices) == 3)
                         $this->buildDataStruct($slices[0], $slices[1], $view, $slices[2]);
                 }
                 # break on custom time ranges
@@ -806,12 +806,12 @@
             }
         }
         #print Kohana::debug($servicelist);
-        if(sizeof($servicelist) > 0 ){
+        if(empty($servicelist)){
+            $this->ERROR = "ERROR: ". Kohana::lang('error.no-data-for-page', $page.".cfg" );
+        }else{
             foreach($servicelist as $s){
                 $this->buildDataStruct($s['host'],$s['service'],$view,$s['source']);
             }
-        }else{
-            $this->ERROR = "ERROR: ". Kohana::lang('error.no-data-for-page', $page.".cfg" );
         }
     }
 
@@ -962,11 +962,11 @@
                 die("Cannot open directory:  $path");
             }
         }
-        if(sizeof($pages)>0){
+        if(empty($pages)){
+            return FALSE; 
+        }else{
             
             natsort($pages);
-        }else{
-            return FALSE; 
         }
         return $pages;
     }
@@ -976,10 +976,10 @@
     */
     public function getFirstPage(){
         $pages = $this->getPages();
-        if(sizeof($pages) > 0 ){
-            return urldecode($pages[0]);
-        }else{
+        if(empty($pages)){
             return FALSE;
+        }else{
+            return urldecode($pages[0]);
         }
     }
 
@@ -1093,7 +1093,7 @@
             }
         }
 
-        if(sizeof($new_hosts) == 0){
+        if(empty($new_hosts)){
             throw new Kohana_Exception('error.tpl-no-hosts-found', $hostregex);
         }
 
@@ -1101,7 +1101,7 @@
         $new_services = array();
         foreach($new_hosts as $host){
             $services = $this->getRawServices($host);
-            if(sizeof($services) == 0){
+            if(empty($services)){
                 throw new Kohana_Exception('error.tpl-no-services-found', $serviceregex);
             }
             foreach($services as $service){
@@ -1115,7 +1115,7 @@
             }
         }
 
-        if(sizeof($new_services) == 0){
+        if(empty($new_services)){
             throw new Kohana_Exception('error.tpl-no-services-found', $serviceregex);
         }
 

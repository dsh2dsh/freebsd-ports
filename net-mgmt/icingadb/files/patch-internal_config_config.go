--- internal/config/config.go.orig	1979-11-29 23:00:00 UTC
+++ internal/config/config.go
@@ -50,7 +50,7 @@ type Flags struct {
 	// Version decides whether to just print the version and exit.
 	Version bool `long:"version" description:"print version and exit"`
 	// Config is the path to the config file
-	Config string `short:"c" long:"config" description:"path to config file" required:"true" default:"/etc/icingadb/config.yml"`
+	Config string `short:"c" long:"config" description:"path to config file" required:"true" default:"%%PREFIX%%/etc/icingadb/config.yml"`
 }
 
 // RetentionConfig defines configuration for history retention.

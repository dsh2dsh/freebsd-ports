--- go.mod.orig	2024-09-27 16:40:42 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/grafana/grafana
 module github.com/grafana/grafana
 
-go 1.22.7
+go 1.22
 
 // contains openapi encoder fixes. remove ASAP
 replace cuelang.org/go => github.com/grafana/cue v0.0.0-20230926092038-971951014e3f // @grafana/grafana-as-code

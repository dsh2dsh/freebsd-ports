--- daemon/job/build_jobs.go.orig
+++ daemon/job/build_jobs.go
@@ -24,21 +24,6 @@ func JobsFromConfig(c *config.Config, parseFlags config.ParseFlags) ([]Job, erro
 		js[i] = j
 	}
 
-	// receiving-side root filesystems must not overlap
-	{
-		rfss := make([]string, 0, len(js))
-		for _, j := range js {
-			jrfs, ok := j.OwnedDatasetSubtreeRoot()
-			if !ok {
-				continue
-			}
-			rfss = append(rfss, jrfs.ToString())
-		}
-		if err := validateReceivingSidesDoNotOverlap(rfss); err != nil {
-			return nil, err
-		}
-	}
-
 	return js, nil
 }
 

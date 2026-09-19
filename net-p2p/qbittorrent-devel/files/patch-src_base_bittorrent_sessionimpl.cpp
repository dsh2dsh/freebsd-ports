--- src/base/bittorrent/sessionimpl.cpp.orig	2026-09-08 23:15:49 UTC
+++ src/base/bittorrent/sessionimpl.cpp
@@ -6768,7 +6768,12 @@ void SessionImpl::handleTorrentConflictAlert(const lt:
             {
                 torrentHandle.set_metadata(metadata->info_section());
             }
-            catch (const std::exception &) {}
+            catch (const std::exception &e)
+              {
+                qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+                LogMsg(tr("Caught exception SessionImpl::handleTorrentConflictAlert: %s")
+                  .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+              }
         });
     }
     else if (torrent1)
@@ -6782,7 +6787,12 @@ void SessionImpl::handleTorrentConflictAlert(const lt:
             {
                 torrentHandle.set_metadata(metadata->info_section());
             }
-            catch (const std::exception &) {}
+            catch (const std::exception &e)
+              {
+                qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+                LogMsg(tr("Caught exception SessionImpl::handleTorrentConflictAlert: %s")
+                  .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+              }
         });
     }
     else
@@ -6969,8 +6979,11 @@ void SessionImpl::updateTrackerEntryStatuses(lt::torre
                 emit trackerEntryStatusesUpdated(torrent, trackers);
             });
         }
-        catch (const std::exception &)
+        catch (const std::exception &e)
         {
+          qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+          LogMsg(tr("Caught exception SessionImpl::updateTrackerEntryStatuses: %s")
+            .arg(QString::fromStdString(e.what())), Log::CRITICAL);
         }
     });
 }

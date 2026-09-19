--- src/base/bittorrent/sessionimpl.cpp.orig	2026-09-08 23:15:49 UTC
+++ src/base/bittorrent/sessionimpl.cpp
@@ -6969,8 +6969,11 @@ void SessionImpl::updateTrackerEntryStatuses(lt::torre
                 emit trackerEntryStatusesUpdated(torrent, trackers);
             });
         }
-        catch (const std::exception &)
+        catch (const std::exception &e)
         {
+          qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+          LogMsg(tr("Caught exception: %s")
+            .arg(QString::fromStdString(e.what())), Log::CRITICAL);
         }
     });
 }

--- src/base/bittorrent/sessionimpl.cpp.orig	2026-09-08 23:15:49 UTC
+++ src/base/bittorrent/sessionimpl.cpp
@@ -2619,9 +2619,17 @@ void SessionImpl::banIP(const QString &ip)
 
     invokeAsync([session = m_nativeSession, addr]
     {
+      try {
         lt::ip_filter filter = session->get_ip_filter();
         filter.add_rule(addr, addr, lt::ip_filter::blocked);
         session->set_ip_filter(std::move(filter));
+      }
+      catch (const std::exception &e)
+      {
+        qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+        LogMsg(tr("Caught exception SessionImpl::banIP: %s")
+          .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+      }
     });
 
     QStringList bannedIPs = m_bannedIPs;
@@ -3188,6 +3196,7 @@ void SessionImpl::enablePortMapping()
 {
     invokeAsync([this]
     {
+      try {
         if (m_isPortMappingEnabled)
             return;
 
@@ -3199,6 +3208,13 @@ void SessionImpl::enablePortMapping()
         m_isPortMappingEnabled = true;
 
         LogMsg(tr("UPnP/NAT-PMP support: ON"), Log::INFO);
+      }
+      catch (const std::exception &e)
+      {
+        qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+        LogMsg(tr("Caught exception SessionImpl::enablePortMapping: %s")
+          .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+      }
     });
 }
 
@@ -3206,6 +3222,7 @@ void SessionImpl::disablePortMapping()
 {
     invokeAsync([this]
     {
+      try {
         if (!m_isPortMappingEnabled)
             return;
 
@@ -3218,6 +3235,13 @@ void SessionImpl::disablePortMapping()
         m_isPortMappingEnabled = false;
 
         LogMsg(tr("UPnP/NAT-PMP support: OFF"), Log::INFO);
+      }
+      catch (const std::exception &e)
+      {
+        qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+        LogMsg(tr("Caught exception SessionImpl::disablePortMapping: %s")
+          .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+      }
     });
 }
 
@@ -3225,6 +3249,7 @@ void SessionImpl::addMappedPorts(const QSet<quint16> &
 {
     invokeAsync([this, ports]
     {
+      try {
         if (!m_isPortMappingEnabled)
             return;
 
@@ -3233,6 +3258,13 @@ void SessionImpl::addMappedPorts(const QSet<quint16> &
             if (!m_mappedPorts.contains(port))
                 m_mappedPorts.insert(port, m_nativeSession->add_port_mapping(lt::session::tcp, port, port));
         }
+      }
+      catch (const std::exception &e)
+      {
+        qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+        LogMsg(tr("Caught exception SessionImpl::addMappedPorts: %s")
+          .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+      }
     });
 }
 
@@ -3240,6 +3272,7 @@ void SessionImpl::removeMappedPorts(const QSet<quint16
 {
     invokeAsync([this, ports]
     {
+      try {
         if (!m_isPortMappingEnabled)
             return;
 
@@ -3253,6 +3286,13 @@ void SessionImpl::removeMappedPorts(const QSet<quint16
 
             return true;
         });
+      }
+      catch (const std::exception &e)
+      {
+        qWarning() << "Caught exception in " << Q_FUNC_INFO << ": " << QString::fromStdString(e.what());
+        LogMsg(tr("Caught exception SessionImpl::removeMappedPorts: %s")
+          .arg(QString::fromStdString(e.what())), Log::CRITICAL);
+      }
     });
 }
 
@@ -6768,7 +6808,12 @@ void SessionImpl::handleTorrentConflictAlert(const lt:
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
@@ -6782,7 +6827,12 @@ void SessionImpl::handleTorrentConflictAlert(const lt:
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
@@ -6969,8 +7019,11 @@ void SessionImpl::updateTrackerEntryStatuses(lt::torre
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

--- syncthingtray/plasmoid/lib/syncthingapplet.h.orig	2026-09-13 15:05:04 UTC
+++ syncthingtray/plasmoid/lib/syncthingapplet.h
@@ -113,7 +113,9 @@ class SyncthingApplet : public Plasma::Applet { (publi
 #if defined(SYNCTHINGWIDGETS_GUI_QTQUICK_MODE_DESKTOP)
     QtGui::QuickUI *quickUI() const;
 #endif
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     Data::SyncthingService *service() const;
+#endif
     QIcon syncthingIcon() const;
     QString incomingTraffic() const;
     bool hasIncomingTraffic() const;
@@ -283,14 +285,12 @@ inline QtGui::QuickUI *SyncthingApplet::quickUI() cons
 }
 #endif
 
+#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
 inline Data::SyncthingService *SyncthingApplet::service() const
 {
-#ifdef LIB_SYNCTHING_CONNECTOR_SUPPORT_SYSTEMD
     return const_cast<Data::SyncthingService *>(&m_service);
-#else
-    return nullptr;
-#endif
 }
+#endif
 
 inline int SyncthingApplet::currentConnectionConfigIndex() const
 {

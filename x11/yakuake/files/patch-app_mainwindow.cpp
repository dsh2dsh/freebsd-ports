--- app/mainwindow.cpp.orig	2024-12-02 23:15:33 UTC
+++ app/mainwindow.cpp
@@ -62,7 +62,7 @@ MainWindow::MainWindow(QWidget *parent)
 #endif
 
 MainWindow::MainWindow(QWidget *parent)
-    : KMainWindow(parent, Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::Tool)
+    : KMainWindow(parent, Qt::CustomizeWindowHint | Qt::FramelessWindowHint)
 {
     QDBusConnection::sessionBus().registerObject(QStringLiteral("/yakuake/window"), this, QDBusConnection::ExportScriptableSlots);
 
@@ -187,7 +187,7 @@ void MainWindow::initWaylandSurface()
         m_plasmaShellSurface = m_plasmaShell->createSurface(surface, this);
         m_plasmaShellSurface->setPosition(pos());
         m_plasmaShellSurface->setSkipTaskbar(true);
-        m_plasmaShellSurface->setSkipSwitcher(true);
+        m_plasmaShellSurface->setSkipSwitcher(false);
     }
 }
 
@@ -935,6 +935,7 @@ void MainWindow::applyWindowProperties()
 void MainWindow::applyWindowProperties()
 {
     if (m_isX11) {
+        KX11Extras::clearState(winId(), NET::SkipSwitcher);
         if (Settings::keepOpen() && !Settings::keepAbove()) {
             KX11Extras::clearState(winId(), NET::KeepAbove);
             KX11Extras::setState(winId(), NET::SkipTaskbar | NET::SkipPager);
@@ -947,7 +948,7 @@ void MainWindow::applyWindowProperties()
 #if HAVE_KWAYLAND
     if (m_isWayland && m_plasmaShellSurface) {
         m_plasmaShellSurface->setSkipTaskbar(true);
-        m_plasmaShellSurface->setSkipSwitcher(true);
+        m_plasmaShellSurface->setSkipSwitcher(false);
     }
 #endif
 

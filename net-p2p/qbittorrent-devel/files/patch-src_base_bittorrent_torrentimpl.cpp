--- src/base/bittorrent/torrentimpl.cpp.orig	2026-09-08 23:15:49 UTC
+++ src/base/bittorrent/torrentimpl.cpp
@@ -1358,7 +1358,10 @@ bool TorrentImpl::hasError() const
 
 bool TorrentImpl::hasError() const
 {
-    return (m_nativeStatus.errc || (m_nativeStatus.flags & lt::torrent_flags::upload_mode));
+    if (m_nativeStatus.errc || (m_nativeStatus.flags & lt::torrent_flags::upload_mode)) return true;
+
+    const TorrentAnnounceStatus st = announceStatus();
+    return st.testFlag(TorrentAnnounceStatusFlag::HasTrackerError);
 }
 
 int TorrentImpl::queuePosition() const
@@ -1385,6 +1388,18 @@ QString TorrentImpl::error() const
 #else
             .arg(Utils::String::fromLocal8Bit(m_lastFileError.error.message()));
 #endif
+    }
+
+    const TorrentAnnounceStatus st = announceStatus();
+    if (st.testFlag(TorrentAnnounceStatusFlag::HasTrackerError)) {
+      for (const TrackerEntryStatus &trackerEntryStatus : asConst(m_trackerEntryStatuses)) {
+        if (trackerEntryStatus.state == BitTorrent::TrackerEndpointState::TrackerError) {
+          if (!trackerEntryStatus.message.isEmpty()) {
+            return trackerEntryStatus.message;
+          }
+        }
+      }
+      return tr("Tracker error");
     }
 
     return {};

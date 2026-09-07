--- src/base/bittorrent/torrentimpl.cpp.orig	2026-07-06 21:07:34 UTC
+++ src/base/bittorrent/torrentimpl.cpp
@@ -1300,7 +1300,10 @@ bool TorrentImpl::hasError() const
 
 bool TorrentImpl::hasError() const
 {
-    return (m_nativeStatus.errc || (m_nativeStatus.flags & lt::torrent_flags::upload_mode));
+    if (m_nativeStatus.errc || (m_nativeStatus.flags & lt::torrent_flags::upload_mode)) return true;
+
+    const TorrentAnnounceStatus st = announceStatus();
+    return st.testFlag(TorrentAnnounceStatusFlag::HasTrackerError);
 }
 
 int TorrentImpl::queuePosition() const
@@ -1317,6 +1320,18 @@ QString TorrentImpl::error() const
     {
         return tr("Couldn't write to file. Reason: \"%1\". Torrent is now in \"upload only\" mode.")
             .arg(Utils::String::fromLocal8Bit(m_lastFileError.error.message()));
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

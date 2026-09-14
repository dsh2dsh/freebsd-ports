--- syncthingtray/syncthingconnector/runtimecondition.cpp.orig	2026-09-13 15:05:04 UTC
+++ syncthingtray/syncthingconnector/runtimecondition.cpp
@@ -119,9 +119,11 @@ class BatteryMonitorBase { (public)
      */
     void queryState(const RuntimeCondition *instance) const
     {
+#ifdef SYNCTHINGCONNECTION_SUPPORT_BATTERY_MONITORING
         instance->m_onBattery = m_onBattery;
         instance->m_batteryLevel = m_batteryLevel;
         instance->m_batterySaving = m_batterySaving;
+#endif
     }
 
 protected:
@@ -130,6 +132,7 @@ class BatteryMonitorBase { (public)
      */
     void updateInstances()
     {
+#ifdef SYNCTHINGCONNECTION_SUPPORT_BATTERY_MONITORING
         for (auto *const instance : RuntimeCondition::s_instances) {
             instance->m_updating = true;
             const auto batteryInfoChanged = instance->setBatteryInfo(m_onBattery, m_batteryLevel);
@@ -139,6 +142,7 @@ class BatteryMonitorBase { (public)
                 instance->updateSupposedToRun();
             }
         }
+#endif
     }
 
     std::optional<bool> m_onBattery; /*!< Whether the system is running on battery. */

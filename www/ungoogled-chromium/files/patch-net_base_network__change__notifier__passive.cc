--- net/base/network_change_notifier_passive.cc.orig	2025-04-15 08:30:07 UTC
+++ net/base/network_change_notifier_passive.cc
@@ -106,7 +106,7 @@ NetworkChangeNotifierPassive::GetAddressMapOwnerIntern
 NetworkChangeNotifier::NetworkChangeCalculatorParams
 NetworkChangeNotifierPassive::NetworkChangeCalculatorParamsPassive() {
   NetworkChangeCalculatorParams params;
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Delay values arrived at by simple experimentation and adjusted so as to
   // produce a single signal when switching between network connections.
   params.ip_address_offline_delay_ = base::Milliseconds(4000);

--- lib/icinga/checkable-dependency.cpp.orig	2022-03-24 04:01:06.000000000 +0100
+++ lib/icinga/checkable-dependency.cpp	2022-03-26 12:34:31.639303000 +0100
@@ -76,8 +76,15 @@
 
 	int countDeps = deps.size();
 	int countFailed = 0;
+	bool hasServiceDep = false;
 
 	for (const Dependency::Ptr& dep : deps) {
+		Host::Ptr    parentHost;
+		Service::Ptr parentService;
+		tie(parentHost, parentService) = GetHostService(dep->GetParent());
+		if (parentService)
+		  hasServiceDep = true;
+
 		if (!dep->IsAvailable(dt)) {
 			countFailed++;
 
@@ -90,6 +97,13 @@
 	if (countDeps > 0 && countFailed == countDeps) {
 		Log(LogDebug, "Checkable")
 			<< "All dependencies have failed for checkable '" << GetName() << "': Marking as unreachable.";
+
+		return false;
+	}
+	/* If there are service dependencies, and any of dependencies failed, mark as unreachable. */
+	else if (hasServiceDep && countFailed > 0) {
+		Log(LogDebug, "Checkable")
+			<< "A dependency has failed for checkable with a service dependency '" << GetName() << "': Marking as unreachable.";
 
 		return false;
 	}

--- lib/icinga/checkable-dependency.cpp.orig
+++ lib/icinga/checkable-dependency.cpp
@@ -83,6 +83,12 @@ bool Checkable::IsReachable(DependencyType dt, Dependency::Ptr *failedDependency
 
 			if (failedDependency)
 				*failedDependency = dep;
+
+                        Host::Ptr    parentHost;
+                        Service::Ptr parentService;
+                        tie(parentHost, parentService) = dep->GetHostService(dep->GetParent());
+                        if (parentService)
+                          return false;
 		}
 	}
 

.include "${USESDIR}/go.mk"

.if !defined(_DSH_INCLUDE_USES_GO_MK)
_DSH_INCLUDE_USES_GO_MK=	yes

.  if ${go_ARGS:Mmodules}
GO_GOPATH=	${DISTDIR}/go
.  endif # ${go_ARGS:Mmodules}

.endif # !defined(_DSH_INCLUDE_USES_GO_MK)

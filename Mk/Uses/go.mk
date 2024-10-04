.if !defined(_INCLUDE_USES_GO_MK)

# If a port USES specific go version and DEFAULT_VERSIONS specifies higher
# version, use it, instead of lower go version from USES. Example:
#
#   DEFAULT_VERSIONS+=	go=1.22
#   USES=	go:1.21
#
# In this example a port builded with lang/go122 instead of lang/go121, because
# DEFAULT_VERSIONS specifies higher version of go.
.  if !defined(GO_STRICT_VERSION)
GO_VERSION=	${go_ARGS:M[1-9].*:U${GO_DEFAULT}}
.    if ${GO_VERSION:N*-devel} && ${GO_VERSION} < ${GO_DEFAULT}
go_ARGS:=	${go_ARGS:S/${GO_VERSION}/${GO_DEFAULT}/1}
.    endif
.  endif

.endif # !defined(_INCLUDE_USES_GO_MK)

.if empty(IGNORE)
.  include "${USESDIR}/go.mk"
.  undef IGNORE
.else
.  include "${USESDIR}/go.mk"
.endif

.if !defined(_DSH_INCLUDE_USES_GO_MK)
_DSH_INCLUDE_USES_GO_MK=	yes

.  if ${go_ARGS:Mmodules}
GO_GOPATH=	${DISTDIR}/go
.  endif # ${go_ARGS:Mmodules}

.endif # !defined(_DSH_INCLUDE_USES_GO_MK)

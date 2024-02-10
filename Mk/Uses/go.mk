.if !defined(IGNORE)
.  include "${USESDIR}/go.mk"
.  undef IGNORE

GO_VALID_VERSIONS+= 1.22

.else
.  include "${USESDIR}/go.mk"
.endif

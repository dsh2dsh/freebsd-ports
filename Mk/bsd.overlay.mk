.if !defined(_DSH_OVERLAY_INCLUDED)
_DSH_OVERLAY_INCLUDED=	yes

.if ${.CURDIR:M*/www/ungoogled-chromium}
.  if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
 # https://chromium.googlesource.com/chromium/src.git/+/master/docs/ccache_mac.md#use-with-gn
 GN_ARGS+= cc_wrapper="${SETENV} CCACHE_SLOPPINESS=time_macros ${CCACHE_BIN}"
.  endif
.endif

.endif # !defined(_DSH_OVERLAY_INCLUDED)

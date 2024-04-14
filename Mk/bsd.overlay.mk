.if !defined(_DSH_OVERLAY_INCLUDED)
_DSH_OVERLAY_INCLUDED=	yes

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
.  if ${.CURDIR:M*/www/firefox}
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224471
MOZ_OPTIONS+=	--with-ccache

.  elif ${.CURDIR:M*/www/ungoogled-chromium}
# https://chromium.googlesource.com/chromium/src.git/+/master/docs/ccache_mac.md#use-with-gn
GN_ARGS+= cc_wrapper="${SETENV} CCACHE_SLOPPINESS=time_macros ${CCACHE_BIN}"

.  endif
.endif # defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)

.endif # !defined(_DSH_OVERLAY_INCLUDED)

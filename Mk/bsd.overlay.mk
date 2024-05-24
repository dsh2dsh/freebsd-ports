.if !defined(_DSH_OVERLAY_INCLUDED)
_DSH_OVERLAY_INCLUDED=	yes

.if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
# From bsd.ccache.mk, because it isn't included yet. The system includes
# bsd.ccache.mk after bsd.overlay.mk.
.  if defined(CCACHE_WRAPPER_PATH)
CCACHE_PKG_PREFIX=	${CCACHE_WRAPPER_PATH:C,/libexec/ccache$,,}
.  endif
CCACHE_PKG_PREFIX?=	${LOCALBASE}
CCACHE_WRAPPER_PATH?=	${CCACHE_PKG_PREFIX}/libexec/ccache
CCACHE_BIN?=		${CCACHE_PKG_PREFIX}/bin/ccache

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=246245
MAKE_ENV+=	CCACHE_BASEDIR="${WRKSRC}" CCACHE_NOHASHDIR=yes
# Disable ccache for test: reduce possible error surface.
TEST_ENV+=	CCACHE_DISABLE=yes
# Disable ccache for configure:
# 1. Performance profit is negative.
# 2. CMake have some issues and may miss /usr/local/include in some cases.
CONFIGURE_ENV+=	CCACHE_DISABLE=yes
CFLAGS+=	-fdebug-prefix-map=${WRKSRC}=.
CXXFLAGS+=	-fdebug-prefix-map=${WRKSRC}=.

.  if ${.CURDIR:M*/www/firefox}
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224471
MOZ_OPTIONS+=	--with-ccache="${CCACHE_BIN}"

.  elif ${.CURDIR:M*/www/ungoogled-chromium}
# https://chromium.googlesource.com/chromium/src.git/+/master/docs/ccache_mac.md#use-with-gn
GN_ARGS+=	cc_wrapper="${CCACHE_BIN}"

.  endif
.endif # defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274142
.if ${.CURDIR:M*/www/firefox}
MAKE_ENV+=	CARGO_BUILD_JOBS=${MAKE_JOBS_NUMBER}
.endif

.endif # !defined(_DSH_OVERLAY_INCLUDED)

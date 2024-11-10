.if !defined(_DSH_OVERLAY_INCLUDED)
_DSH_OVERLAY_INCLUDED=	yes

.  if defined(SCCACHE_DIR)
SCCACHE_DIR:=	${SCCACHE_DIR}
.  elif defined(CCACHE_DIR)
SCCACHE_DIR:=	${CCACHE_DIR}/sccache
.  endif

.  if defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)
# From bsd.ccache.mk, because it isn't included yet. The system includes
# bsd.ccache.mk after bsd.overlay.mk, but we need CCACHE_BIN.
.	 if defined(CCACHE_WRAPPER_PATH)
CCACHE_PKG_PREFIX=	${CCACHE_WRAPPER_PATH:C,/libexec/ccache$,,}
.	 endif
CCACHE_PKG_PREFIX?=	${LOCALBASE}
CCACHE_WRAPPER_PATH?=	${CCACHE_PKG_PREFIX}/libexec/ccache
CCACHE_BIN?=		${CCACHE_PKG_PREFIX}/bin/ccache

PATH:=	${CCACHE_PKG_PREFIX}/bin:${PATH}

# Use separate CCACHE_DIR if defined
.    if defined(CCACHE_SUBDIR)
CCACHE_DIR:=	${CCACHE_DIR}/${CCACHE_SUBDIR}
.    endif # defined(WITH_CCACHE_SUBDIR)

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=246245
MAKE_ENV+=	CCACHE_BASEDIR="${WRKSRC}" CCACHE_NOHASHDIR=yes
TEST_ENV+=	CCACHE_BASEDIR="${WRKSRC}" CCACHE_NOHASHDIR=yes
CONFIGURE_ENV+=	CCACHE_BASEDIR="${WRKSRC}" CCACHE_NOHASHDIR=yes \
	CMAKE_C_COMPILER_LAUNCHER="${CCACHE_BIN}" \
	CMAKE_CXX_COMPILER_LAUNCHER="${CCACHE_BIN}"
CFLAGS+=	-fdebug-prefix-map=${WRKSRC}=.
CXXFLAGS+=	-fdebug-prefix-map=${WRKSRC}=.

_USES_configure+=	250:ccache-update-links

.    if ${.CURDIR:M*/www/firefox}
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224471
MOZ_OPTIONS+=	--with-ccache="${CCACHE_BIN}"

.    elif ${.CURDIR:M*/www/ungoogled-chromium}
# https://chromium.googlesource.com/chromium/src.git/+/master/docs/ccache_mac.md#use-with-gn
GN_ARGS+=	cc_wrapper="${CCACHE_BIN}"

.    endif
.  endif # defined(WITH_CCACHE_BUILD) && !defined(NO_CCACHE)

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274142
.  if ${.CURDIR:M*/www/firefox}
MAKE_ENV+=	CARGO_BUILD_JOBS=${MAKE_JOBS_NUMBER}
USES+=	gecko
.  endif

ccache-update-links:
	@${ECHO_MSG} "==> ccache-update-links"
	ccache-update-links -v

.endif # !defined(_DSH_OVERLAY_INCLUDED)

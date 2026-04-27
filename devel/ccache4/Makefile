PORTNAME=	ccache
DISTVERSIONPREFIX=	v
DISTVERSION=	4.13.5
CATEGORIES=	devel
PKGNAMESUFFIX=	4

MAINTAINER=	osidorkin@gmail.com
COMMENT=	Tool to minimize the compile time of C/C++ programs
WWW=		https://ccache.dev/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/GPL-3.0.txt

USES=		cmake:noninja compiler:c++17-lang pathfix shebangfix
USE_GITHUB=	yes

SHEBANG_FILES=	doc/scripts/* test/*
SHEBANG_GLOB=	*.sh *.bash

CMAKE_ARGS+=	-D DEPS=LOCAL
CMAKE_OFF=	ENABLE_IPO ENABLE_TRACING WARNINGS_AS_ERRORS

TEST_TARGET=		check

CONFLICTS_INSTALL?=	ccache ccache-static

# Prevent infinite recursion.
NO_CCACHE=	yes
NO_CCACHE_DEPEND=	yes
SUB_FILES=	ccache-update-links.sh ccache_clean world-ccache

PORTDOCS=	AUTHORS.html AUTHORS.md LICENSE.md MANUAL.html MANUAL.md \
		NEWS.html NEWS.md authors.adoc manual.adoc news.adoc

OPTIONS_DEFINE=		CLANGLINK DOCS LLVMLINK STATIC TEST
OPTIONS_DEFAULT=	CLANGLINK LLVMLINK STATIC
OPTIONS_SUB=		yes

CLANGLINK_DESC=		Create clang compiler links if clang is installed
HIREDIS_DESC=		Enable high-performance libhiredis storage backend
LLVMLINK_DESC=		Create llvm compiler links if llvm is installed

DOCS_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
			bash:shells/bash \
			pandoc:textproc/hs-pandoc
DOCS_USES=		groff:run perl5
DOCS_CMAKE_BOOL=	ENABLE_DOCUMENTATION
DOCS_ALL_TARGET=	all doc

HIREDIS_CMAKE_BOOL=	REDIS_STORAGE_BACKEND
STATIC_BUILD_DEPENDS=	${LOCALBASE}/lib/libxxhash.a:devel/xxhash \
			${LOCALBASE}/lib/libzstd.a:archivers/zstd
STATIC_LIB_DEPENDS_OFF=	libfmt.so:devel/libfmt \
			libxxhash.so:devel/xxhash \
			libzstd.so:archivers/zstd
STATIC_CMAKE_BOOL=	STATIC_LINK
STATIC_CMAKE_ON=	-DDEP_BLAKE3=BUNDLED \
			-DDEP_CPPHTTPLIB=BUNDLED \
			-DDEP_FMT=BUNDLED \
			-DDEP_NONSTDSPAN=BUNDLED \
			-DDEP_TLEXPECTED=BUNDLED
STATIC_LDFLAGS=		-static

TEST_BUILD_DEPENDS=	doctest>=2.4.6:devel/doctest
TEST_TEST_DEPENDS=	bash:shells/bash \
			objdump:devel/binutils
TEST_USES=		perl5
TEST_CMAKE_BOOL=	ENABLE_TESTING
TEST_TEST_TARGET=	check

.include <bsd.port.pre.mk>

CCLINKDIR=		libexec/ccache
PLIST_SUB+=		CCLINKDIR="${CCLINKDIR}"

.if ${ARCH}=="i386"
CCACHE_COMPILERS+=	icc icpc
.endif

GNU_COMPILERS+=		12 13 14 15 16
CCACHE_COMPILERS+=	cc c++ CC gcc g++ ${GNU_COMPILERS:S|^|gcc|} \
			${GNU_COMPILERS:S|^|g++|} ${GNU_COMPILERS:S|^|cpp|}

.if ${PORT_OPTIONS:MCLANGLINK}
CLANG_COMPILERS+=	12 13 14 15 16 17 18 19 20 21 22 -devel
CCACHE_COMPILERS+=	clang clang++ ${CLANG_COMPILERS:S|^|clang|} \
			${CLANG_COMPILERS:S|^|clang++|} \
			${CLANG_COMPILERS:S|^|cpp|}
.endif

.if ${PORT_OPTIONS:MLLVMLINK}
CCACHE_COMPILERS+=	 llvm-c++ llvm-g++ llvm-gcc
.endif

.if ${PORT_OPTIONS:MHIREDIS}
.  if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhiredis.a:databases/hiredis
.  else
LIB_DEPENDS+=	libhiredis.so:databases/hiredis
.  endif
.endif

CCACHE_COMPILERS+=	${EXTRA_COMPILERS}
SUB_LIST+=		CCACHE_COMPILERS="${CCACHE_COMPILERS}" \
			CCLINKDIR="${CCLINKDIR}"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${CCLINKDIR}/world
	${INSTALL_SCRIPT} ${WRKDIR}/world-ccache \
		${STAGEDIR}${PREFIX}/${CCLINKDIR}/world/ccache
	${INSTALL_SCRIPT} ${WRKDIR}/ccache-update-links.sh \
		${STAGEDIR}${PREFIX}/bin/ccache-update-links
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/ccache_clean \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.adoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.adoc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

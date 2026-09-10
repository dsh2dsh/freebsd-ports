PORTNAME=	libtorrent-rasterbar
DISTVERSION=	2.0.13
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/arvidn/libtorrent/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	20

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library implementing a BitTorrent client
WWW=		https://libtorrent.org \
		https://github.com/arvidn/libtorrent

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_chrono.so:devel/boost-libs \
		libboost_random.so:devel/boost-libs \
		libboost_thread.so:devel/boost-libs

USES=		cmake:testing compiler:c++11-lib iconv:wchar_t \
		localbase:ldflags pathfix pkgconfig python:test shebangfix ssl

USE_CXXSTD=	c++17 # prevent boost-related SEGV, see bug#264278
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py

CMAKE_TESTING_ON=	build_tests

LDFLAGS+=	${ICONV_LIB}

CONFLICTS_INSTALL=	libtorrent-rasterbar libtorrent-rasterbar2

DOCFILES=	AUTHORS ChangeLog
PORTDOCS=	${DOCFILES} docs/*
PORTEXAMPLES=	*.cpp

OPTIONS_DEFINE=		DOCS EXAMPLES LOGGING
OPTIONS_DEFAULT=	LOGGING
OPTIONS_SUB=		yes
LOGGING_DESC=		Enable logging to disk

EXAMPLES_CMAKE_BOOL=	build_examples
LOGGING_CMAKE_BOOL=	logging

post-patch:
	@${REINPLACE_CMD} -e 's|"python3"|"${PYTHON_CMD:T}"|' \
		${WRKSRC}/test/setup_transfer.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/docs/._*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

# tests as of 2.0.11: 99% tests passed, 1 tests failed out of 106, see https://github.com/arvidn/libtorrent/issues/7837

.include <bsd.port.mk>

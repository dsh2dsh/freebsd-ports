PORTNAME=	hunspell
PORTVERSION=	2024.04.18
CATEGORIES=	russian textproc
PKGNAMEPREFIX=	ru-

MAINTAINER=	office@FreeBSD.org
COMMENT=	Russian hunspell dictionaries

LICENSE=	LGPL3

USE_GITHUB=	nodefault
GH_ACCOUNT=	LibreOffice
GH_PROJECT=	dictionaries
GH_TAGNAME=	fc2dc38
GH_TUPLE:=	${GH_ACCOUNT}:${GH_PROJECT}:${GH_TAGNAME}:${PORTNAME}

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_SANITIZED}
WRKSRC_SUBDIR=	ru_RU
EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT}-${GH_TAGNAME}/${WRKSRC_SUBDIR}/* \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/ru_RU.aff ${DATADIR}/ru_RU.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ru_RU.aff ${WRKSRC}/ru_RU.dic \
		${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>

PORTNAME=	hunspell
PORTVERSION=	2021.07.28
DISTVERSION=	fc2dc38
CATEGORIES=	textproc
PKGNAMEPREFIX=	cs-

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech hunspell dictionaries

USE_GITHUB=	yes
GH_ACCOUNT=	LibreOffice
GH_PROJECT=	dictionaries

WRKSRC_SUBDIR=	cs_CZ
EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT}-${GH_TAGNAME}/${WRKSRC_SUBDIR}/* \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/cs_CZ.aff ${DATADIR}/cs_CZ.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/cs_CZ.aff ${WRKSRC}/cs_CZ.dic \
		${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>

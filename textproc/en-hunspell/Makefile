PORTNAME=	hunspell
PORTVERSION=	2024.05.01
CATEGORIES=	textproc
PKGNAMEPREFIX=	en-

MAINTAINER=	office@FreeBSD.org
COMMENT=	English hunspell dictionaries

LICENSE=	BSD3CLAUSE

USE_GITHUB=	nodefault
GH_ACCOUNT=	LibreOffice
GH_PROJECT=	dictionaries
GH_TAGNAME=	fc2dc38
GH_TUPLE:=	${GH_ACCOUNT}:${GH_PROJECT}:${GH_TAGNAME}:${PORTNAME}

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME_SANITIZED}
WRKSRC_SUBDIR=	en
EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT}-${GH_TAGNAME}/${WRKSRC_SUBDIR}/* \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/README_en_AU.txt \
				${DATADIR}/README_en_CA.txt \
				${DATADIR}/README_en_GB.txt \
				${DATADIR}/README_en_US.txt \
				${DATADIR}/README_en_ZA.txt \
				${DATADIR}/en_AU.aff \
				${DATADIR}/en_AU.dic \
				${DATADIR}/en_CA.aff \
				${DATADIR}/en_CA.dic \
				${DATADIR}/en_GB.dic \
				${DATADIR}/en_GB.aff \
				${DATADIR}/en_US.aff \
				${DATADIR}/en_US.dic \
				${DATADIR}/en_ZA.aff \
				${DATADIR}/en_ZA.dic

GBALIASES=	en_AG en_BS en_BW en_BZ en_DK en_GH en_HK en_IE en_IN en_JM en_NA \
			en_NG en_NZ en_SG en_TT en_ZW
USALIASES=	en_PH

.for ALIAS in ${GBALIASES} ${USALIASES}
PLIST_FILES+=	${DATADIR}/${ALIAS}.aff ${DATADIR}/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/README_en_??.txt ${WRKSRC}/en_*.aff \
		${WRKSRC}/en_*.dic \
		${STAGEDIR}${DATADIR}/

.for ALIAS in ${GBALIASES}
	${LN} -s en_GB.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_GB.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.for ALIAS in ${USALIASES}
	${LN} -s en_US.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_US.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

.include <bsd.port.mk>

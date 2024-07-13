PORTNAME=	hunspell
PORTVERSION=	2024.05.01
DISTVERSION=	7272a82
CATEGORIES=	textproc
PKGNAMEPREFIX=	en-

MAINTAINER=	office@FreeBSD.org
COMMENT=	English hunspell dictionaries

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	LibreOffice
GH_PROJECT=	dictionaries

EXTRACT_AFTER_ARGS=	--include ${GH_PROJECT}-${GH_TAGNAME}/en/* \
			--no-same-owner --no-same-permissions
WRKSRC_SUBDIR=	en

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/README_en_AU${AU_VARIANT}.txt \
		${DATADIR}/README_en_CA${CA_VARIANT}.txt \
		${DATADIR}/README_en_GB${GB_VARIANT}.txt \
		${DATADIR}/README_en_US${US_VARIANT}.txt \
		${DATADIR}/en_AU${AU_VARIANT}.aff \
		${DATADIR}/en_AU${AU_VARIANT}.dic \
		${DATADIR}/en_CA${CA_VARIANT}.aff \
		${DATADIR}/en_CA${CA_VARIANT}.dic \
		${DATADIR}/en_GB${GB_VARIANT}.dic \
		${DATADIR}/en_GB${GB_VARIANT}.aff \
		${DATADIR}/en_US${US_VARIANT}.aff \
		${DATADIR}/en_US${US_VARIANT}.dic \
		${DATADIR}/en_GB.dic \
		${DATADIR}/en_GB.aff

COPY=		-lh	# Use hardlinks rather than copies under stage/

OPTIONS_RADIO=	AU CA GB US
OPTIONS_RADIO_AU=	AU_STANDARD AU_LARGE
OPTIONS_RADIO_CA=	CA_STANDARD CA_LARGE
OPTIONS_RADIO_GB=	GB_ISE GB_IZE GB_LARGE
OPTIONS_RADIO_US=	US_STANDARD US_LARGE
OPTIONS_DEFAULT=AU_STANDARD CA_STANDARD GB_ISE US_STANDARD
AU_LARGE_DESC=		Dictionary with more words and multiple variants per word
AU_STANDARD_DESC=	Australian dictionary considered standard by maintainers
CA_LARGE_DESC=		Dictionary with more words and multiple variants per word
CA_STANDARD_DESC=	Canadian dictionary considered standard by maintainers
GB_ISE_DESC=		en_GB dictionary with -ise spelling
GB_IZE_DESC=		en_GB dictionary with -ize spelling
GB_LARGE_DESC=		Dictionary with more words and multiple variants per word
US_LARGE_DESC=		Dictionary with more words and multiple variants per word
US_STANDARD_DESC=	American dictionary considered standard by maintainers

.for c in AU CA GB US
.	for v in STANDARD ISE IZE LARGE
${c}_${v}_VARS=		${c}_VARIANT=${v:S/STANDARD//:tl:C/^.+$/-&/}
.	endfor
.endfor

AU_LARGE_PLIST_FILES=	${DATADIR}/en_AU.aff ${DATADIR}/en_AU.dic
CA_LARGE_PLIST_FILES=	${DATADIR}/en_CA.aff ${DATADIR}/en_CA.dic
US_LARGE_PLIST_FILES=	${DATADIR}/en_US.aff ${DATADIR}/en_US.dic

GBALIASES=	en_AG en_BS en_BW en_BZ en_DK en_GH en_HK en_IE en_IN en_JM en_NA en_NG en_NZ en_SG en_TT en_ZA en_ZW
USALIASES=	en_PH

.for ALIAS in ${GBALIASES} ${USALIASES}
PLIST_FILES+=	${DATADIR}/${ALIAS}.aff \
		${DATADIR}/${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/*.aff ${WRKSRC}/*.dic ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/README_*.txt ${STAGEDIR}${DATADIR}/
	${LN} -s en_GB${GB_VARIANT}.aff ${STAGEDIR}${DATADIR}/en_GB.aff
	${LN} -s en_GB${GB_VARIANT}.dic ${STAGEDIR}${DATADIR}/en_GB.dic
.for ALIAS in ${GBALIASES}
	${LN} -s en_GB.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_GB.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor
.for ALIAS in ${USALIASES}
	${LN} -s en_US.aff ${STAGEDIR}${DATADIR}/${ALIAS}.aff
	${LN} -s en_US.dic ${STAGEDIR}${DATADIR}/${ALIAS}.dic
.endfor

do-install-AU_LARGE-on:
	${LN} -s en_AU-large.aff ${STAGEDIR}${DATADIR}/en_AU.aff
	${LN} -s en_AU-large.dic ${STAGEDIR}${DATADIR}/en_AU.dic

do-install-CA_LARGE-on:
	${LN} -s en_CA-large.aff ${STAGEDIR}${DATADIR}/en_CA.aff
	${LN} -s en_CA-large.dic ${STAGEDIR}${DATADIR}/en_CA.dic

do-install-US_LARGE-on:
	${LN} -s en_US-large.aff ${STAGEDIR}${DATADIR}/en_US.aff
	${LN} -s en_US-large.dic ${STAGEDIR}${DATADIR}/en_US.dic

.include <bsd.port.mk>

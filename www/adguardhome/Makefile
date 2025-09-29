PORTNAME=	adguardhome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.107.67
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSIONFULL}/
DISTFILES=	${GH_PROJECT}_frontend${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network-wide ads & trackers blocking DNS server
WWW=		https://adguard.com/en/adguard-home/overview.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	AdguardTeam
GH_PROJECT=	AdGuardHome

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_MOD_DIST=	github
# workaround for https://github.com/AdguardTeam/AdGuardHome/issues/4774
_BUILD_XFLAGS=	${GO_MODULE}/internal/version.version=${DISTVERSION}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S/^/-X /}"

USER=		root # it has to run as root because it listens on the privileged DNS port
GROUP=		wheel
SUB_LIST=	USER=${USER} GROUP=${GROUP}
USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	PORTNAME=${PORTNAME}

CPE_VENDOR=	adguard

pre-build:
	${CP} -r ${WRKDIR}/build ${WRKSRC}/

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf

.include <bsd.port.mk>

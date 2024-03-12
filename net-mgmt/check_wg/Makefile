PORTNAME=	         check_wg
DISTVERSIONPREFIX= v
DISTVERSION=       0.0.2
CATEGORIES=        net-mgmt

MAINTAINER=        dsh@bamus.cz
COMMENT=           Icinga2 health check of wireguard peers, using output of wg(8)
WWW=               https://github.com/dsh2dsh/check_wg

LICENSE=           MIT
LICENSE_FILE=      ${WRKSRC}/LICENSE

USES=              go:modules

GO_MODULE=         github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=     -ldflags="-s -w"

PLIST_FILES=       libexec/nagios/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>

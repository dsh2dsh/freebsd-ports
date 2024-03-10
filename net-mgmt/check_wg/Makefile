PORTNAME=	         check_wg
DISTVERSIONPREFIX= v
DISTVERSION=       0.0.1
CATEGORIES=        net-mgmt

MAINTAINER=        dsh@bamus.cz
COMMENT=           Icinga2 health check of wireguard peers, using output of wg(8)
WWW=               https://github.com/dsh2dsh/check_wg

LICENSE=           MIT
LICENSE_FILE=      ${WRKSRC}/LICENSE

USES=              go:modules

GO_MODULE=         github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=     -ldflags="-s -w"

PLIST_FILES=       bin/${PORTNAME}

.include <bsd.port.mk>

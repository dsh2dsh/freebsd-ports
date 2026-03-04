PORTNAME=	expx-dbcopy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	sysutils

MAINTAINER=	dsh@bamus.cz
COMMENT=	Wait and cat an S3 file

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
_BUILD_XFLAGS=	main.version=${DISTVERSION}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S!^!-X !}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

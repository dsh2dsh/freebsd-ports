PORTNAME=		expx-dbcopy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=		sysutils

MAINTAINER=		dsh@bamus.cz
COMMENT=		Wait and cat an S3 file
WWW=			https://github.com/dsh2dsh/${PORTNAME}

LICENSE=		MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=			go:modules

GO_MODULE=		github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="${STRIP} -w -X main.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

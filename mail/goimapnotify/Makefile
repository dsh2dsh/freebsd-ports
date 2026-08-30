PORTNAME=	goimapnotify
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1-23-g242b57e
CATEGORIES=	mail

MAINTAINER=	dsh@bamus.cz
COMMENT=	Execute scripts on IMAP or JMAP mailbox changes

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.27+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
_BUILD_COMMIT=	242b57e
_BUILD_XFLAGS=	cli.commit=${_BUILD_COMMIT} \
		cli.gittag=${DISTVERSIONFULL} \
		cli.branch=master
GO_LDFLAGS=	${_BUILD_XFLAGS:S!^!-X ${GO_MODULE}/internal/!}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

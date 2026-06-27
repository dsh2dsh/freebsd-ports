PORTNAME=	goimapnotify
DISTVERSION=	2.5.6
CATEGORIES=	mail

MAINTAINER=	dsh@bamus.cz
COMMENT=	Execute scripts on IMAP mailbox changes (new/deleted/updated messages) using IDLE

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITLAB=	yes
GL_ACCOUNT=	shackra

GO_MOD_DIST=	gitlab
GO_MODULE=	gitlab.com/${GL_ACCOUNT}/${PORTNAME}
_BUILD_COMMIT=	251292f1
_BUILD_XFLAGS=	main.commit=${_BUILD_COMMIT} \
		main.gittag=${DISTVERSIONFULL} \
		main.branch=master
GO_LDFLAGS=	${_BUILD_XFLAGS:S!^!-X !}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

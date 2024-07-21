PORTNAME=	fzf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54.1
CATEGORIES=	textproc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Blazing fast command-line fuzzy finder
WWW=		https://github.com/junegunn/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/junegunn/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.version=${DISTVERSION} -X main.revision=${COMMIT_ID} ${STRIP} -w"

COMMIT_ID=	50fa90d

PLIST_FILES=	bin/fzf share/man/man1/fzf.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

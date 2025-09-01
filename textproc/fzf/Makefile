PORTNAME=	fzf
DISTVERSION=	0.65.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Blazing fast command-line fuzzy finder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	junegunn

USES=		go:modules

_BUILD_COMMIT=	416aff8
_BUILD_XFLAGS=	main.revision=${COMMIT_ID} \
		main.version=${DISTVERSION}

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S/^/-X /}"

PLIST_FILES=	bin/fzf share/man/man1/fzf.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/fzf.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>

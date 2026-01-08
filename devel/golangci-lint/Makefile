PORTNAME=	golangci-lint
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Linters Runner for Go
WWW=		https://github.com/golangci/golangci-lint

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	golangci

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	e2e4002
_BUILD_DATE=	date -u "+%Y-%m-%dT%H:%M:%SZ"
_BUILD_XFLAGS=	main.version=${_BUILD_VERSION} \
		main.commit=${_BUILD_COMMIT} \
		main.date=${_BUILD_DATE:sh}

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}/v2
GO_MOD_DIST=	github
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S/^/-X /}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md
PORTEXAMPLES=	.golangci.reference.yml

OPTIONS_DEFINE=		COMPLETIONS DOCS EXAMPLES
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${SET_ENV} ${MAKE_ENV} ${GO_ENV} ${GO_WRKDIR_BIN}/${PORTNAME} completion ${_shell} \
		>${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

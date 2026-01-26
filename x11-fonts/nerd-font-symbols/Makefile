PORTNAME=	nerd-font-symbols
DISTVERSION=	3.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/nerd-fonts/releases/download/v${DISTVERSION}/
DISTNAME=	NerdFontsSymbolsOnly

MAINTAINER=	dsh@bamus.cz
COMMENT=	Just the Nerd Font Icons. I.e Symbol font only.
WWW=		https://nerdfonts.com/

LICENSE=	MIT

USES=		fonts tar:xz
GH_ACCOUNT=	ryanoasis

CONFLICTS_INSTALL=	nerd-fonts

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKDIR} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>

PORTNAME=	iosevka-comfy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	x11-fonts

MAINTAINER=	dsh@bamus.cz
COMMENT=	Iosevka Comfy - customised build of the Iosevka typeface

# The license file is not downloaded.
LICENSE=	OFL11

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	protesilaos
GH_TAGNAME=	c7cfc91

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} iosevka-comfy\* ${STAGEDIR}${FONTSDIR})

.include <bsd.port.mk>

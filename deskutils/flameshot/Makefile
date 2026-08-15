PORTNAME=	flameshot
PORTVERSION=	14.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils wayland

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software
WWW=		https://flameshot.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang desktop-file-utils qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	flameshot-org

USE_QT=		base imageformats svg tools:build

CMAKE_INSTALL_PREFIX=	${STAGEDIR}/${PREFIX}

post-patch:
	${REINPLACE_CMD} \
		-e 's,$${CMAKE_INSTALL_FULL_BINDIR},${LOCALBASE}/bin,1' \
		-e 's,^\(Exec=\)@LAUNCHER_EXECUTABLE@,\1${LOCALBASE}/bin/${PORTNAME},1' \
		${WRKSRC}/data/dbus/org.flameshot.Flameshot.service.in \
		${WRKSRC}/data/desktopEntry/package/org.flameshot.Flameshot.desktop

.include <bsd.port.mk>

PORTNAME=	bsdisks
DISTVERSION=	0.35
CATEGORIES=	sysutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UDisks2 service implementation for FreeBSD
WWW=		https://foss.heptapod.net/bsdutils/bsdisks

LICENSE=	BSD3CLAUSE

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_PKGNAMESUFFIX=	-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt-1@${FLAVOR}

USES=		cmake compiler:c++11-lang

.if ${FLAVOR} == qt5
CMAKE_ARGS=	-DQT_MAJOR_VERSION=5
USES+=		qt:5
USE_QT=		qmake:build buildtools:build core dbus
.else
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6
USES+=		qt:6
USE_QT=		base
.endif

USE_GITLAB=		yes
GL_SITE=		https://foss.heptapod.net
GL_ACCOUNT=		bsdutils
GL_TAGNAME=		205d242c512099074c3c1bf939a4fd83139bb5c8

.include <bsd.port.mk>

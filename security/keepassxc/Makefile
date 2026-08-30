PORTNAME=	keepassxc
DISTVERSION=	2.7.12-20260830
CATEGORIES=	security

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	KeePass Cross-platform Community Edition
WWW=		https://keepassxc.org

LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 MIT \
		NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror \
					pkg-sell auto-accept

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libbotan-3.so:security/botan3 \
		libpcsclite.so:devel/pcsc-lite \
		libqrencode.so:graphics/libqrencode \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang desktop-file-utils minizip \
		pkgconfig qt:6 readline shared-mime-info tar:xz xorg

USE_GITHUB=	yes
GH_ACCOUNT=	keepassxreboot
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	79c3c37

USE_QT=		base svg tools:build
USE_XORG=	x11 xtst

CMAKE_OFF=	KPXC_FEATURE_UPDATES

CONFLICTS_INSTALL=	keepassx keepassx-0.* keepassx2 keepassxc276

OPTIONS_DEFINE=		BROWSER FDOSECRETS NETWORKING SSHAGENT
OPTIONS_DEFAULT=	BROWSER FDOSECRETS NETWORKING SSHAGENT
OPTIONS_SUB=		yes

BROWSER_DESC=		Browser integration with KeePassXC-Browser
FDOSECRETS_DESC=	freedesktop.org secrets service support
NETWORKING_DESC=	Networking support (e.g. for downloading website icons)
SSHAGENT_DESC=		SSH agent support

BROWSER_CMAKE_BOOL=	KPXC_FEATURE_BROWSER

FDOSECRETS_CMAKE_BOOL=	KPXC_FEATURE_FDOSECRETS

NETWORKING_CMAKE_BOOL=	KPXC_FEATURE_NETWORK

SSHAGENT_CMAKE_BOOL=	KPXC_FEATURE_SSHAGENT

.include <bsd.port.mk>

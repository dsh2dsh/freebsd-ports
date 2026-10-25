PORTNAME=	ChiPass
DISTVERSION=	2026.09.0
CATEGORIES=	security
MASTER_SITES=	https://codeberg.org/ChiPass/ChiPass/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	dsh@bamus.cz
COMMENT=	Cross-platform password manager forked from KeePassXC
WWW=		https://chipass.org/

LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 MIT \
		NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror \
					pkg-sell auto-accept

BUILD_DEPENDS=	appstreamcli:devel/appstream \
		asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libbotan-3.so:security/botan3 \
		libqrencode.so:graphics/libqrencode \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang desktop-file-utils gl minizip \
		pkgconfig qt:6 readline shared-mime-info tar:bz2 xorg

USE_GL=		opengl
USE_QT=		5compat base svg tools:build translations
USE_XORG=	x11 xext

CMAKE_ARGS=	-DCHIPASS_BUILD_TYPE=Release
CMAKE_OFF=	CHIPASS_WITH_GUI_TESTS \
		CHIPASS_WITH_TESTS \
		CHIPASS_WITH_UPDATE_CHECK

EXTRACT_AFTER_ARGS=	--directory ${WRKSRC}

OPTIONS_DEFINE=		AUTOTYPE BROWSER FDOSECRETS KEESHARE NETWORKING \
			PASSKEYS SSHAGENT YUBIKEY
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		yes

AUTOTYPE_DESC=		Auto-type passwords in input fields
BROWSER_DESC=		Browser integration with KeePassXC-Browser
FDOSECRETS_DESC=	freedesktop.org secrets service support
KEESHARE_DESC=		Sharing integration with KeeShare
NETWORKING_DESC=	Networking support (e.g. for downloading website icons)
PASSKEYS_DESC=		Passkeys support for browser integration (implies BROWSER)
SSHAGENT_DESC=		SSH agent support
YUBIKEY_DESC=		YubiKey support (broken on <= 14.x)

AUTOTYPE_USE=		XORG=xi,xtst
AUTOTYPE_CMAKE_BOOL=	CHIPASS_WITH_AUTOTYPE

BROWSER_CMAKE_BOOL=	CHIPASS_WITH_BROWSER

FDOSECRETS_CMAKE_BOOL=	CHIPASS_WITH_FDOSECRETS

KEESHARE_CMAKE_BOOL=	CHIPASS_WITH_KEESHARE

NETWORKING_CMAKE_BOOL=	CHIPASS_WITH_NETWORKING

PASSKEYS_IMPLIES=	BROWSER
PASSKEYS_CMAKE_BOOL=	CHIPASS_WITH_BROWSER_PASSKEYS

SSHAGENT_CMAKE_BOOL=	CHIPASS_WITH_SSHAGENT

YUBIKEY_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
YUBIKEY_CMAKE_BOOL=	CHIPASS_WITH_YUBIKEY

pre-extract:
	${MKDIR} ${WRKSRC}

post-stage:
.for f in ChiPass.1 ChiPass-cli.1
	${MV} ${STAGEDIR}${PREFIX}/share/${PORTNAME}/man/man1/${f} \
		${STAGEDIR}${PREFIX}/share/man/man1/${f}
.endfor

.include <bsd.port.mk>

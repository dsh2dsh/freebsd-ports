PORTNAME=	qbittorrent-devel
PORTVERSION=	20260916
CATEGORIES=	net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bittorrent client using Qt6 and libtorrent-rasterbar
WWW=		https://www.qbittorrent.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtorrent-rasterbar.so:net-p2p/libtorrent-rasterbar2

FLAVORS=	default nox
FLAVOR?=	${FLAVORS:[1]}
nox_PKGNAMESUFFIX=	-nox
nox_PLIST=	${MASTERDIR}/pkg-plist-nox

USES=		compiler:c++14-lang cpe pkgconfig cmake localbase qt:6 ssl
USE_QT=		base translations

USE_GITHUB=	yes
GH_ACCOUNT=	qBittorrent
GH_PROJECT=	qBittorrent
GH_TAGNAME=	9b0e931

.if ${FLAVOR} == default
USES+=			desktop-file-utils gl
USE_QT+=		svg
USE_GL=			gl
CMAKE_OFF=		WEBUI
.endif

.if ${FLAVOR} == nox
COMMENT+=		(web UI version)
USE_RC_SUBR=		qbittorrent
CMAKE_OFF=		GUI
SUB_LIST=		USER=${USERS} GROUP=${GROUPS}
PLIST_SUB=		USER=${USERS} GROUP=${GROUPS}
OPTIONS_EXCLUDE=	DBUS
USERS=			qbittorrent
GROUPS=			qbittorrent
.endif

# error: "Boost.Stacktrace requires `_Unwind_Backtrace` function. Define
# `_GNU_SOURCE` macro or `BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED` if
# _Unwind_Backtrace is available without `_GNU_SOURCE`."
CXXFLAGS+=	-DBOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED

CONFLICTS_INSTALL=	qbittorrent

OPTIONS_DEFINE=			DBUS PYTHON DEBUG
OPTIONS_DEFAULT=		DBUS PYTHON

PYTHON_DESC=		Install Python to support some plugin functionality

DBUS_CMAKE_BOOL=	DBUS

DEBUG_CMAKE_BOOL=	debug

PYTHON_USES=		python:run

.include <bsd.port.options.mk>

post-patch-PYTHON-on:
	@${REINPLACE_CMD} \
		-e 's|"python3"|"${PYTHON_CMD}"|' \
		${WRKSRC}/src/base/utils/foreignapps.cpp

.if ${FLAVOR} == nox
post-install:
	${MKDIR} \
		${STAGEDIR}/var/db/qbittorrent/conf \
		${STAGEDIR}/var/db/qbittorrent/Downloads
.endif

.include <bsd.port.mk>

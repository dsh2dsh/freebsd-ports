PORTNAME=	icinga2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.0
CATEGORIES=	net-mgmt

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Monitoring and management system for hosts, services and networks
WWW=		https://www.icinga.org/icinga2/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libprotobuf-lite.so:devel/protobuf \
		libabsl_base.so:devel/abseil
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		bison cmake:insource compiler:c++0x libedit ssl
USE_GITHUB=	yes
GH_ACCOUNT=	icinga

USE_LDCONFIG=	yes

USE_RC_SUBR=	${PORTNAME}

CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_INSTALL_LOCALSTATEDIR=${LOCALSTATEDIR} \
		-DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/etc \
		-DCMAKE_MODULE_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_SHARED_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_STATIC_LINKER_FLAGS=${PREFIX}/lib/icinga2 \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man \
		-DICINGA2_COMMAND_GROUP=${ICINGA2USER} \
		-DICINGA2_COMMAND_USER=${ICINGA2USER} \
		-DICINGA2_GROUP=${ICINGA2GROUP} \
		-DICINGA2_PLUGINDIR=${LOCALBASE}/libexec/nagios \
		-DICINGA2_RUNDIR=/var/run \
		-DICINGA2_USER=${ICINGA2USER}

SUB_FILES=	${PORTNAME}-newsyslog.conf pkg-message

SUB_LIST=	ICINGA2GROUP=${ICINGA2GROUP} \
		ICINGA2LOGDIR=${ICINGA2LOGDIR} \
		ICINGA2USER=${ICINGA2USER} \
		WWWGRP=${WWWGRP}

ICINGA2USER?=	icinga
ICINGA2GROUP?=	icinga
USERS=		${ICINGA2USER}
GROUPS=		${ICINGA2GROUP}

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		ICINGA2GROUP=${ICINGA2GROUP} \
		ICINGA2USER=${ICINGA2USER} \
		WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS EXAMPLES LTO UNITY
OPTIONS_DEFAULT=	MONPLUGINS MYSQL PGSQL UNITY
OPTIONS_GROUP=	BACKEND
OPTIONS_GROUP_BACKEND=	MYSQL PGSQL
OPTIONS_RADIO=	PLUGINS
OPTIONS_RADIO_PLUGINS=	MONPLUGINS NAGPLUGINS
OPTIONS_SUB=	yes

UNITY_DESC=	Use icinga unity build system (faster, memory intensive)

LTO_CMAKE_BOOL=	ICINGA2_LTO_BUILD

MONPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/monitoring-plugins

MYSQL_USES=	mysql
MYSQL_CMAKE_OFF=	-DICINGA2_WITH_MYSQL=OFF

NAGPLUGINS_RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:net-mgmt/nagios-plugins

PGSQL_USES=	pgsql
PGSQL_CMAKE_OFF=	-DICINGA2_WITH_PGSQL=OFF

UNITY_CMAKE_OFF=	-DICINGA2_UNITY_BUILD=OFF

LOCALSTATEDIR?=	/var
ICINGA2LOGDIR?=	/var/log/${PORTNAME}

# Config files with references to "Linux"
LINUX_CONFIG=	groups.conf services.conf hosts.conf

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	DBBACKEND="@comment "
.else
PLIST_SUB+=	DBBACKEND=""
.endif

post-patch:
.for f in ${LINUX_CONFIG}
	${REINPLACE_CMD} 's,[Ll]inux,FreeBSD,g' ${WRKSRC}/etc/icinga2/conf.d/${f}
.endfor

pre-install:
	${FIND} ${WRKSRC}/etc -type f -name "*.conf" -exec ${MV} {} {}.sample \;
	${FIND} ${WRKSRC}/etc/icinga2/scripts -type f -name "*.sh" \
		-exec ${MV} {} {}.sample \;

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/newsyslog/
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-newsyslog.conf ${STAGEDIR}${EXAMPLESDIR}/newsyslog/${PORTNAME}.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles
	(cd ${WRKSRC}/tools/syntax/vim && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles)

.include <bsd.port.mk>

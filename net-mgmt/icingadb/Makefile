PORTNAME=	icingadb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	net-mgmt

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Publish, synchronize, and visualize Icinga data
WWW=		https://icinga.com/docs/icinga-db/latest/doc/02-Installation/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules pgsql

WANT_PGSQL=	contrib

USE_RC_SUBR=	icingadb

PLIST_SUB=	PORTNAME=${PORTNAME}

# As copied from net-mgmt/icinga2
ICINGA2USER?=	icinga
ICINGA2GROUP?=	icinga
USERS=		${ICINGA2USER}
GROUPS=		${ICINGA2GROUP}

SUB_LIST=	ICINGA2GROUP=${ICINGA2GROUP} \
		ICINGA2USER=${ICINGA2USER}

GO_MODULE=	github.com/icinga/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "${STRIP} -w"

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/internal/config/config.go

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "schema" ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/config.example.yml \
		${STAGEDIR}${ETCDIR}/config.yml.sample
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf

.include <bsd.port.mk>

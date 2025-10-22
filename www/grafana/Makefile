PORTNAME=	grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	12.2.1
CATEGORIES=	www
MASTER_SITES=	https://dl.grafana.com/oss/release/ \
		https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	${PORTNAME}-${DISTVERSION}.linux-amd64${EXTRACT_SUFX} \
		go.mod:gomod \
		go.work:gomod \
		apps/advisor/go.mod:gomod \
		apps/alerting/alertenrichment/go.mod:gomod \
		apps/alerting/notifications/go.mod:gomod \
		apps/dashboard/go.mod:gomod \
		apps/folder/go.mod:gomod \
		apps/iam/go.mod:gomod \
		apps/investigations/go.mod:gomod \
		apps/playlist/go.mod:gomod \
		apps/plugins/go.mod:gomod \
		apps/preferences/go.mod:gomod \
		apps/provisioning/go.mod:gomod \
		apps/secret/go.mod:gomod \
		apps/shorturl/go.mod:gomod \
		pkg/aggregator/go.mod:gomod \
		pkg/apimachinery/go.mod:gomod \
		pkg/apiserver/go.mod:gomod \
		pkg/build/go.mod:gomod \
		pkg/build/wire/go.mod:gomod \
		pkg/codegen/go.mod:gomod \
		pkg/plugins/codegen/go.mod:gomod \
		pkg/promlib/go.mod:gomod \
		pkg/semconv/go.mod:gomod
EXTRACT_ONLY=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//:Ngo.work}

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Dashboard and graph editor for multiple data stores
WWW=		https://grafana.com/${PORTNAME}/ \
		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 riscv64

USES=		cpe go:modules

USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

_BUILD_COMMIT=	563109b
_BUILD_XFLAGS=	main.version=${PORTVERSION} \
		main.commit=${_BUILD_COMMIT}

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_MOD_DIST=	github
GO_TARGET=	./pkg/cmd/${PORTNAME} \
		./pkg/cmd/${PORTNAME}-server \
		./pkg/cmd/${PORTNAME}-cli
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S/^/-X /}"

CONFLICTS_INSTALL=	grafana*

SUB_LIST=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANA_DATADIR=${GRAFANA_DATADIR} \
		GRAFANA_HOMEDIR=${GRAFANA_HOMEDIR} \
		GRAFANA_LOGDIR=${GRAFANA_LOGDIR} \
		GRAFANA_PLUGINDIR=${GRAFANA_PLUGINDIR} \
		GRAFANA_PROVISIONINGDIR=${GRAFANA_PROVISIONINGDIR}
# Disable some master port targets
TARGET_ORDER_OVERRIDE=	-1:go-post-extract

GRAFANA_USER?=	${PORTNAME}
GRAFANA_GROUP?=	${PORTNAME}

USERS=		${GRAFANA_USER}
GROUPS=		${GRAFANA_GROUP}

PLIST_SUB=	${SUB_LIST}

GRAFANA_DATADIR?=		/var/db/${PORTNAME}
GRAFANA_HOMEDIR?=		${DATADIR}
GRAFANA_LOGDIR?=		/var/log/${PORTNAME}
GRAFANA_PLUGINDIR?=		${GRAFANA_DATADIR}/plugins
GRAFANA_PROVISIONINGDIR?=	${ETCDIR}/provisioning

post-extract:
	${ECHO_MSG} "===> Tidying ${GO_MODNAME} dependencies";
	(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	${ECHO_MSG} "===> Vendoring ${GO_MODNAME} dependencies";
	(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} work vendor -e)

post-patch:
	${REINPLACE_CMD} \
		-e 's|;data = /var/lib/grafana|data = ${GRAFANA_DATADIR}|g' \
		-e 's|;logs = /var/log/grafana|logs = ${GRAFANA_LOGDIR}|g' \
		-e 's|;plugins = /var/lib/grafana/plugins|plugins = ${GRAFANA_PLUGINDIR}|g' \
		-e 's|;provisioning = conf/provisioning|provisioning = ${GRAFANA_PROVISIONINGDIR}|g' \
		 ${WRKSRC}/conf/sample.ini

pre-build:
	(cd ${GO_WRKSRC}; \
	${ECHO_MSG} "===>  Generating wire_gen.go"; \
	${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run \
		./pkg/build/wire/cmd/wire/main.go gen -tags "oss" ./pkg/server)

post-install:
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANA_DATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_PLUGINDIR}
.for dir in access-control alerting dashboards datasources plugins
	${MKDIR} ${STAGEDIR}${GRAFANA_PROVISIONINGDIR}/${dir}
.endfor
	${MKDIR} ${STAGEDIR}${GRAFANA_LOGDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} public ${STAGEDIR}${GRAFANA_HOMEDIR})
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini \
		${STAGEDIR}${GRAFANA_HOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKSRC}/conf/sample.ini \
		${STAGEDIR}${ETCDIR}/grafana.ini.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ldap.toml \
		${STAGEDIR}${ETCDIR}/ldap.toml.sample
	${FIND} ${STAGEDIR}${DATADIR}/public -type f | \
		${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

.include <bsd.port.mk>

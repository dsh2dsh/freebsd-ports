PORTNAME=          zrepl
DISTVERSIONPREFIX= v
DISTVERSION=       0.7.3
DISTVERSIONSUFFIX= -0.20240504201609-32632e326460

CATEGORIES=        sysutils

MAINTAINER=        dsh@bamus.cz
COMMENT=           ZFS dataset replication tool
WWW=               https://github.com/dsh2dsh/${PORTNAME}

LICENSE=           MIT
LICENSE_FILE=      ${WRKSRC}/LICENSE

USES=              go:modules ncurses
USE_RC_SUBR=       ${PORTNAME}

GO_MODULE=         github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=     -ldflags "${STRIP} -w -X github.com/${PORTNAME}/${PORTNAME}/version.${PORTNAME}Version=${DISTVERSIONFULL}"

SUB_FILES=         pkg-message 500.zrepl

OPTIONS_DEFINE=    EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}${PREFIX}/etc/syslog.d \
		${STAGEDIR}/var/run/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
	${INSTALL_DATA} ${FILESDIR}/syslog.conf ${STAGEDIR}${EXAMPLESDIR}/syslog.conf
	${INSTALL_DATA} ${FILESDIR}/zrepl.yml ${STAGEDIR}${ETCDIR}/zrepl.yml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/weekly
	${INSTALL_SCRIPT} ${WRKDIR}/500.zrepl \
		${STAGEDIR}${PREFIX}/etc/periodic/weekly/500.zrepl

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/hooks
	(cd ${WRKSRC}/config/samples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/dist/grafana/grafana-prometheus-zrepl.json \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

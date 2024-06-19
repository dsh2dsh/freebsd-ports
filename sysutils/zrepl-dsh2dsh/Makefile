PORTNAME=		zrepl-dsh2dsh
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.8

CATEGORIES=		sysutils

MAINTAINER=		dsh@bamus.cz
COMMENT=		ZFS dataset replication tool (fork with more features)
WWW=			https://github.com/dsh2dsh/zrepl

LICENSE=		MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	zrepl

USES=			go:1.22,modules ncurses
USE_RC_SUBR=	zrepl

GO_MODULE=		github.com/dsh2dsh/zrepl
GO_BUILDFLAGS=	-ldflags "${STRIP} -w -X github.com/dsh2dsh/zrepl/version.zreplVersion=${DISTVERSIONFULL}"

SUB_FILES=		pkg-message 500.zrepl

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}/var/run/zrepl
	${INSTALL_DATA} ${FILESDIR}/newsyslog.conf \
		${STAGEDIR}${EXAMPLESDIR}/newsyslog.conf
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

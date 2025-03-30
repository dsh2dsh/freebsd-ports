PORTNAME=	fcron
DISTVERSION=	3.4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://fcron.free.fr/archives/ \
		ftp://ftp.seul.org/pub/fcron/
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

MAINTAINER=	bob@eager.cx
COMMENT=	Periodic command scheduler
WWW=		http://fcron.free.fr/

LICENSE=	GPLv2

USES=		perl5 gmake
USE_PERL5=	build
USE_RC_SUBR=	fcron

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-cflags="${CFLAGS}" \
		--with-rootname=root --with-rootgroup=wheel \
		--with-docdir=${DOCSDIR} \
		--with-dsssl-dir=no

SUB_FILES=	pkg-message

USERS=		fcron
GROUPS=		fcron

PAMDIR?=	etc/pam.d
PLIST_SUB+=	PAMDIR=etc/pam.d

PORTDOCS=	*

DOCSRC=		${WRKSRC}/doc/en

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${MKDIR} -m 770 ${STAGEDIR}/var/spool/${PORTNAME}

	${INSTALL_PROGRAM} ${WRKSRC}/fcron ${STAGEDIR}${PREFIX}/sbin
.for f in fcrontab fcrondyn fcronsighup
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.for f in fcron fcrontab
	${INSTALL_DATA} ${WRKSRC}/files/${f}.pam \
		${STAGEDIR}${PREFIX}/${PAMDIR}/${f}
.endfor

.for f in fcron.allow fcron.conf fcron.deny
	${INSTALL_DATA} -m 640 ${WRKSRC}/files/${f} \
		${STAGEDIR}${PREFIX}/etc/${f}.sample
.endfor

.for n in 1 5 8
	${INSTALL_MAN} ${DOCSRC}/man/*.${n} \
		${STAGEDIR}${PREFIX}/share/man/man${n}
.endfor

do-install-DOCS-on:
.for d in txt HTML
	${MKDIR} ${STAGEDIR}${DOCSDIR}/${d}
	${INSTALL_DATA} ${DOCSRC}/${d}/* ${STAGEDIR}${DOCSDIR}/${d}
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/fcrontab-root ${WRKSRC}/files/*.pam \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

PORTNAME=	openrsync
PORTVERSION=	0.0.20250924
CATEGORIES=	net
PKGNAMESUFFIX=	-ks

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Implementation of rsync with a BSD (ISC) license
WWW=		https://github.com/KlaraSystems/${PORTNAME}

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	kyua:devel/kyua \
		cstream:misc/cstream

USE_GITHUB=	yes
GH_ACCOUNT=	KlaraSystems
GH_TAGNAME=	a548ebb

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	MANDIR=${PREFIX}/share/man

CONFLICTS_INSTALL=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/man/man5/${PORTNAME}.5.gz \
		share/man/man5/${PORTNAME}d.5.gz \
		share/man/man5/${PORTNAME}d.conf.5.gz

OPTIONS_DEFINE=	TEST

TEST_TARGET=	run
TEST_WRKSRC=	${WRKSRC}/tests/src

pre-build:
.for SUFFIX in rsync.5 rsyncd.5 rsyncd.conf.5
	${MV} ${WRKSRC}/${SUFFIX} ${WRKSRC}/open${SUFFIX}
	${REINPLACE_CMD} \
		-e 's|Nm rsync|Nm openrsync|g' \
		-e 's|rsync 5|openrsync 5|ig' \
		-e 's|rsyncd 5|openrsyncd 5|ig' \
		${WRKSRC}/open${SUFFIX}
.endfor
	${REINPLACE_CMD} \
		-e 's|rsync.5|openrsync.5|g' \
		-e 's|rsyncd.5|openrsyncd.5|g' \
		-e 's|rsyncd.conf.5|openrsyncd.conf.5|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's|rsync 5|openrsync 5|ig' \
		-e 's|rsyncd 5|openrsyncd 5|ig' \
		-e 's|rsyncd.conf 5|openrsyncd.conf 5|ig' \
		${WRKSRC}/${PORTNAME}.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

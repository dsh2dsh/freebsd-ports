PORTNAME=	openrsync-ks
PORTVERSION=	0.0.20250924
CATEGORIES=	net

MAINTAINER=	scf@FreeBSD.org
COMMENT=	Implementation of rsync with a BSD (ISC) license
WWW=		https://github.com/KlaraSystems/openrsync

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	KlaraSystems
GH_PROJECT=	openrsync
GH_TAGNAME=	a548ebb

TEST_DEPENDS=	kyua:devel/kyua \
		cstream:misc/cstream

CONFLICTS_INSTALL=	openrsync
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	MANDIR=${PREFIX}/share/man
TEST_TARGET=	run
TEST_WRKSRC=	${WRKSRC}/tests/src

OPTIONS_DEFINE=	TEST

PLIST_FILES=	bin/openrsync share/man/man1/openrsync.1.gz \
		share/man/man5/openrsync.5.gz share/man/man5/openrsyncd.5.gz \
		share/man/man5/openrsyncd.conf.5.gz

pre-build:
.for SUFFIX in rsync.5 rsyncd.5 rsyncd.conf.5
	${MV} ${WRKSRC}/${SUFFIX} ${WRKSRC}/open${SUFFIX}
	${REINPLACE_CMD}	-e 's|Nm rsync|Nm openrsync|g'	\
				-e 's|rsync 5|openrsync 5|ig'	\
				-e 's|rsyncd 5|openrsyncd 5|ig'	\
				${WRKSRC}/open${SUFFIX}
.endfor
	${REINPLACE_CMD}	-e 's|rsync.5|openrsync.5|g'		\
				-e 's|rsyncd.5|openrsyncd.5|g'		\
				-e 's|rsyncd.conf.5|openrsyncd.conf.5|g'\
				${WRKSRC}/Makefile
	${REINPLACE_CMD}	-e 's|rsync 5|openrsync 5|ig'		\
				-e 's|rsyncd 5|openrsyncd 5|ig'		\
				-e 's|rsyncd.conf 5|openrsyncd.conf 5|ig'\
				${WRKSRC}/openrsync.1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/openrsync

.include <bsd.port.mk>

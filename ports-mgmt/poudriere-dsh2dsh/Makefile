PORTNAME=	poudriere
DISTVERSION=	3.4.99.20250602
CATEGORIES=	ports-mgmt
PKGNAMESUFFIX=	-dsh2dsh

MAINTAINER=	dsh@bamus.cz
COMMENT=	Port build and test system (fork with more features)

LICENSE=	BSD2CLAUSE

# gmake is not strictly needed but handles test jobs better
TEST_DEPENDS=	gmake>0:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GNU_CONFIGURE=	yes

.if make(test)
MAKE_CMD=	gmake
.endif
TEST_ARGS=	-s
TEST_ARGS+=	${_MAKE_JOBS}
TEST_ENV=	MAKE=gmake
TEST_TARGET=	check

CONFLICTS_INSTALL=	poudriere*

ETCDIR=		${PREFIX}/etc/poudriere.d

OPTIONS_DEFINE=	BASH MANIFESTS PORTCONFIG EXAMPLES QEMU ZSH
OPTIONS_DEFAULT=BASH MANIFESTS PORTCONFIG ZSH
OPTIONS_SUB=	yes

MANIFESTS_DESC=		Install manifests for jail creation
PORTCONFIG_DESC=	Install portconfig for options command
QEMU_DESC=	Add qemu-user-static for non-x86 architectures

MANIFESTS_RUN_DEPENDS+=	freebsd-release-manifests>0:misc/freebsd-release-manifests
PORTCONFIG_RUN_DEPENDS=	portconfig>0:ports-mgmt/portconfig
QEMU_RUN_DEPENDS=	qemu-user-static>0:emulators/qemu-user-static

# ccache passthrough helps for building pkg a few hundred times.
# ccache not added as a dependency because it is only used if setup
# and provided in the env already.
# XXX: Passthrough local PKGREPOSITORY dir for fetch support
ccache_vars=	CCACHE_DIR_NON_ROOT_SAFE CCACHE_GROUP \
		CCACHE_GID CCACHE_STATIC_PREFIX CCACHE_TEMPDIR \
		CCACHE_DIR CCACHE_NLEVELS
.for _cv in ${ccache_vars}
.  if !empty(${_cv})
TEST_ENV+=	${_cv}=${${_cv}}
.  endif
.endfor

.include <bsd.port.options.mk>

# rm -x support came in 10.0.  A bundled rm is used if not supported in base.
# While <10 is technically not supported in the Ports Tree, Poudriere
# detects this and it being a package build tool it should still be
# supported as a user may be installing this to build packages for upgrading
# their system to a supported release.
.if ${OSVERSION} < 1000000
PLIST_SUB+=	RM=""
.else
PLIST_SUB+=	RM="@comment "
.endif

post-patch:
	${REINPLACE_CMD} \
	    -e "s,^\(POUDRIERE_VERSION\)=.*,\1='${PKGVERSION}'," \
	    ${WRKSRC}/src/bin/poudriere.in

post-install:
	${LN} -fs ${LOCALBASE}/share/freebsd/MANIFESTS \
	    ${STAGEDIR}${DATADIR}/MANIFESTS

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/completions/bash/poudriere \
	    ${STAGEDIR}${PREFIX}/share/bash-completion/completions/

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_poudriere \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>

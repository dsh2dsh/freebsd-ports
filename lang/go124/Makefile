DISTVERSION=	1.24.0
# Always set PORTREVISION explicitly as otherwise they are inherited from lang/go-devel
MASTER_SITES=	https://golang.org/dl/
DISTFILES=	go${DISTVERSION}.src.tar.gz \
		go1.23.6.${OPSYS:tl}-${GOARCH_${ARCH}}.tar.gz

# Avoid conflicting patch files
PATCHFILES=
PATCHDIR=	${.CURDIR}/files

COMMENT=	Go programming language

MASTERDIR=	${.CURDIR}/../go-devel
WRKSRC=		${WRKDIR}/go
DISTINFO_FILE=	${.CURDIR}/distinfo
EXTRACT_ONLY=	${DISTFILES:[1]}

SHEBANG_FILES?=	lib/wasm/go_js_wasm_exec lib/wasm/go_wasip1_wasm_exec

BOOTSTRAP_WRKDIR=	${WRKDIR}/go-${OPSYS:tl}-${GOARCH_${ARCH}}${GOARM_${ARCH}}-bootstrap

pre-extract:
	${MKDIR} "${BOOTSTRAP_WRKDIR}"
	(cd "${BOOTSTRAP_WRKDIR}" && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		"${DISTDIR}/${DIST_SUBDIR}/${DISTFILES:[2]}" \
		--strip-components 1 ${EXTRACT_AFTER_ARGS})

.include "${MASTERDIR}/Makefile"

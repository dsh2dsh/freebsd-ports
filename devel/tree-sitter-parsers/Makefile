PORTNAME=	tree-sitter-parsers
PORTVERSION=	20250306
CATEGORIES=	devel

MAINTAINER=	dsh@bamus.cz
COMMENT=	Collection of language grammars for use with tree-sitter
WWW=		https://github.com/tree-sitter/tree-sitter

USE_GITHUB=	nodefault

_TUPLES=\
	awk		Beaglefoot:tree-sitter-awk:v0.7.2 \
	agda		tree-sitter:tree-sitter-agda:v1.3.3 \
	bash		tree-sitter:tree-sitter-bash:v0.23.3 \
	bibtex		latex-lsp:tree-sitter-bibtex:ccfd77d \
	blueprint	huanie:tree-sitter-blueprint:e8d4fec \
	c		tree-sitter:tree-sitter-c:v0.23.5 \
	c-sharp		tree-sitter:tree-sitter-c-sharp:v0.23.1 \
	clojure		sogaiu:tree-sitter-clojure:v0.0.13 \
	cmake		uyha:tree-sitter-cmake:v0.6.1 \
	commonlisp	tree-sitter-grammars:tree-sitter-commonlisp:v0.3.3 \
	cpp		tree-sitter:tree-sitter-cpp:v0.23.4 \
	css		tree-sitter:tree-sitter-css:v0.23.2 \
	dart		ast-grep:tree-sitter-dart:23e3921 \
	dockerfile	camdencheek:tree-sitter-dockerfile:v0.2.0 \
	elixir		elixir-lang:tree-sitter-elixir:v0.3.4 \
	embedded-template	tree-sitter:tree-sitter-embedded-template:v0.23.2 \
	glsl		tree-sitter-grammars:tree-sitter-glsl:v0.1.9 \
	go		tree-sitter:tree-sitter-go:v0.23.4 \
	gomod		camdencheek:tree-sitter-go-mod:v1.1.0 \
	haskell		tree-sitter:tree-sitter-haskell:v0.23.1 \
	heex		phoenixframework:tree-sitter-heex:v0.8.0 \
	html		tree-sitter:tree-sitter-html:v0.23.2 \
	janet		sogaiu:tree-sitter-janet-simple:v0.0.7 \
	java		tree-sitter:tree-sitter-java:v0.23.5 \
	javascript	tree-sitter:tree-sitter-javascript:v0.23.1 \
	jsdoc		tree-sitter:tree-sitter-jsdoc:v0.23.2 \
	json		tree-sitter:tree-sitter-json:v0.24.8 \
	julia		tree-sitter:tree-sitter-julia:v0.23.1 \
	kotlin		fwcd:tree-sitter-kotlin:0.3.8 \
	lua		tree-sitter-grammars:tree-sitter-lua:v0.2.0 \
	magik		krn-robin:tree-sitter-magik:0.0.1 \
	make		tree-sitter-grammars:tree-sitter-make:v1.1.1 \
	markdown	tree-sitter-grammars:tree-sitter-markdown:v0.3.2 \
	nix		nix-community:tree-sitter-nix:v0.0.2 \
	nu		nushell:tree-sitter-nu:b99dc3b \
	ocaml		tree-sitter:tree-sitter-ocaml:v0.24.0 \
	org		milisims:tree-sitter-org:v1.3.1 \
	perl		ganezdragon:tree-sitter-perl:v1.1.1 \
	php		tree-sitter:tree-sitter-php:v0.23.12 \
	proto		mitchellh:tree-sitter-proto:42d82fa \
	python		tree-sitter:tree-sitter-python:v0.23.6 \
	r		r-lib:tree-sitter-r:v1.1.0 \
	regex		tree-sitter:tree-sitter-regex:v0.24.3 \
	ruby		tree-sitter:tree-sitter-ruby:v0.23.1 \
	rust		tree-sitter:tree-sitter-rust:v0.23.2 \
	scala		tree-sitter:tree-sitter-scala:v0.23.4 \
	sql		DerekStride:tree-sitter-sql:9376414 \
	surface		connorlay:tree-sitter-surface:v0.2.0 \
	toml		tree-sitter:tree-sitter-toml:v0.5.1 \
	tsx		tree-sitter:tree-sitter-typescript:v0.23.2 \
	typst		uben0:tree-sitter-typst:v0.11.0 \
	verilog		gmlarumbe:tree-sitter-verilog:cd6e48b \
	vhdl		alemuller:tree-sitter-vhdl:a3b2d84 \
	vue		tree-sitter-grammars:tree-sitter-vue:7e48557 \
	wast		wasm-lsp:tree-sitter-wasm:2ca28a9 \
	wgsl		mehmetoguzderin:tree-sitter-wgsl:27ae4db \
	yaml		tree-sitter-grammars:tree-sitter-yaml:v0.7.0

_SRCDIR.markdown=	tree-sitter-markdown/src
_SRCDIR.ocaml=		grammars/ocaml/src
_SRCDIR.php=		php/src
_SRCDIR.tsx=		tsx/src
_SRCDIR.wast=		wast/src

_ADDONS=\
	markdown-inline	markdown/tree-sitter-markdown-inline/src \
	ocaml-interface	ocaml/grammars/interface/src \
	ocaml-type	ocaml/grammars/type/src \
	typescript	tsx/typescript/src \
	wat		wast/wat/src

LANG_FILTER=	S/-/_/

.for lang tuple in ${_TUPLES}
GH_TUPLE+=	${tuple}:${lang:${LANG_FILTER}}/${lang}
.endfor

.for lang tuple in ${_TUPLES}
_BUILD+=	${lang} ${lang}/${_SRCDIR.${lang:${LANG_FILTER}}:Usrc}
.endfor
.for lang dir in ${_ADDONS}
_BUILD+=	${lang} ${dir}
.endfor

do-build: build-all-parsers

do-install: install-all-parsers

.include <bsd.port.mk>

.for lang dir in ${_BUILD}
_LANGS+=	${WRKSRC}/${dir}/libtree-sitter-${lang}.so
SRCS.${lang:${LANG_FILTER}}+=	${dir}/parser.c
.  if exists(${WRKSRC}/${dir}/scanner.c)
SRCS.${lang:${LANG_FILTER}}+=	${dir}/scanner.c
.  endif
.  if exists(${WRKSRC}/${dir}/scanner.cc)
SRCS.${lang:${LANG_FILTER}}+=	${dir}/scanner.cc
.  endif

${WRKSRC}/${dir}/libtree-sitter-${lang}.so: ${SRCS.${lang:${LANG_FILTER}}:R:S/$/.o/:S!^!${WRKSRC}/!}
.  if exists(${WRKSRC}/${dir}/scanner.cc)
	${CXX} ${CXXFLAGS} -fPIC -shared -o ${.TARGET} ${.ALLSRC}
.  else
	${CC}  ${CXXFLAGS} -fPIC -shared -o ${.TARGET} ${.ALLSRC}
.  endif
.endfor

.c.o:
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CC} \
		${CFLAGS}   -fPIC -c -I${.TARGET:H} -o ${.TARGET} ${.IMPSRC}

.cc.o:
	${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${CXX} \
		${CXXFLAGS} -fPIC -c -I${.TARGET:H} -o ${.TARGET} ${.IMPSRC}

build-all-parsers: ${_LANGS}

install-all-parsers:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${_LANGS} ${STAGEDIR}${PREFIX}/lib

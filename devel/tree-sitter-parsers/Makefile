PORTNAME=	tree-sitter-parsers
PORTVERSION=	20250305
CATEGORIES=	devel

MAINTAINER=	dsh@bamus.cz
COMMENT=	Collection of parsers for use with tree-sitter
WWW=		https://github.com/tree-sitter/tree-sitter

USE_GITHUB=	nodefault

_RECIPES=\
	awk	src	Beaglefoot:tree-sitter-awk:v0.7.2 \
	bash	src	tree-sitter:tree-sitter-bash:v0.23.3 \
	bibtex	src	latex-lsp:tree-sitter-bibtex:ccfd77d \
	blueprint	src	huanie:tree-sitter-blueprint:e8d4fec \
	c	src	tree-sitter:tree-sitter-c:v0.23.5 \
	c-sharp	src	tree-sitter:tree-sitter-c-sharp:v0.23.1 \
	clojure	src	sogaiu:tree-sitter-clojure:v0.0.13 \
	cmake	src	uyha:tree-sitter-cmake:v0.6.1 \
	commonlisp	src	tree-sitter-grammars:tree-sitter-commonlisp:v0.3.3 \
	cpp	src	tree-sitter:tree-sitter-cpp:v0.23.4 \
	css	src	tree-sitter:tree-sitter-css:v0.23.2 \
	dart	src	ast-grep:tree-sitter-dart:23e3921 \
	dockerfile	src	camdencheek:tree-sitter-dockerfile:v0.2.0 \
	elixir	src	elixir-lang:tree-sitter-elixir:v0.3.4 \
	glsl	src	tree-sitter-grammars:tree-sitter-glsl:v0.1.9 \
	go	src	tree-sitter:tree-sitter-go:v0.23.4 \
	gomod	src	camdencheek:tree-sitter-go-mod:v1.1.0 \
	heex	src	phoenixframework:tree-sitter-heex:v0.8.0 \
	html	src	tree-sitter:tree-sitter-html:v0.23.2 \
	janet	src	sogaiu:tree-sitter-janet-simple:v0.0.7 \
	java	src	tree-sitter:tree-sitter-java:v0.23.5 \
	javascript	src	tree-sitter:tree-sitter-javascript:v0.23.1 \
	json	src	tree-sitter:tree-sitter-json:v0.24.8 \
	julia	src	tree-sitter:tree-sitter-julia:v0.23.1 \
	kotlin	src	fwcd:tree-sitter-kotlin:0.3.8 \
	lua	src	tree-sitter-grammars:tree-sitter-lua:v0.2.0 \
	magik	src	krn-robin:tree-sitter-magik:0.0.1 \
	make	src	tree-sitter-grammars:tree-sitter-make:v1.1.1 \
	markdown	tree-sitter-markdown/src \
		tree-sitter-grammars:tree-sitter-markdown:v0.3.2 \
	nix	src	nix-community:tree-sitter-nix:v0.0.2 \
	nu	src	nushell:tree-sitter-nu:b99dc3b \
	org	src	milisims:tree-sitter-org:v1.3.1 \
	perl	src	ganezdragon:tree-sitter-perl:v1.1.1 \
	proto	src	mitchellh:tree-sitter-proto:42d82fa \
	python	src	tree-sitter:tree-sitter-python:v0.23.6 \
	r	src	r-lib:tree-sitter-r:v1.1.0 \
	ruby	src	tree-sitter:tree-sitter-ruby:v0.23.1 \
	rust	src	tree-sitter:tree-sitter-rust:v0.23.2 \
	scala	src	tree-sitter:tree-sitter-scala:v0.23.4 \
	sql	src	DerekStride:tree-sitter-sql:9376414 \
	surface	src	connorlay:tree-sitter-surface:v0.2.0 \
	toml	src	tree-sitter:tree-sitter-toml:v0.5.1 \
	tsx	tsx/src	tree-sitter:tree-sitter-typescript:v0.23.2 \
	typst	src	uben0:tree-sitter-typst:v0.11.0 \
	verilog	src	gmlarumbe:tree-sitter-verilog:cd6e48b \
	vhdl	src	alemuller:tree-sitter-vhdl:a3b2d84 \
	vue	src	tree-sitter-grammars:tree-sitter-vue:7e48557 \
	wast	wast/src	wasm-lsp:tree-sitter-wasm:2ca28a9 \
	wgsl	src	mehmetoguzderin:tree-sitter-wgsl:27ae4db \
	yaml	src	tree-sitter-grammars:tree-sitter-yaml:v0.7.0

_ADDONS=\
	markdown-inline	markdown/tree-sitter-markdown-inline/src \
	typescript	tsx/typescript/src \
	wat		wast/wat/src

.for lang dir tuple in ${_RECIPES}
GH_TUPLE+=	${tuple}:${lang:S/-/_/}/${lang}
.endfor

.for lang dir tuple in ${_RECIPES}
_BUILD+=	${lang} ${lang}/${dir}
.endfor
.for lang dir in ${_ADDONS}
_BUILD+=	${lang} ${dir}
.endfor

do-build:
.for lang dir in ${_BUILD}
	(cd ${WRKSRC}/${dir} && ${CC}  -fPIC -c -I. parser.c)

.  if exists(${WRKSRC}/${dir}/scanner.c)
	(cd ${WRKSRC}/${dir} && ${CC}  -fPIC -c -I. scanner.c)
.  endif

.  if exists(${WRKSRC}/${dir}/scanner.cc)
	(cd ${WRKSRC}/${dir} && ${CXX} -fPIC -c -I. scanner.c)
.  endif

.  if exists(${WRKSRC}/${dir}/scanner.cc)
	(cd ${WRKSRC}/${dir} && \
	${CXX} -fPIC -shared -o libtree-sitter-${lang}.so *.o)
.  else
	(cd ${WRKSRC}/${dir} && \
	${CC}  -fPIC -shared -o libtree-sitter-${lang}.so *.o)
.  endif
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib
.for lang dir in ${_BUILD}
	${INSTALL_LIB} ${WRKSRC}/${dir}/libtree-sitter-${lang}.so \
		${STAGEDIR}${PREFIX}/lib
.endfor

.include <bsd.port.mk>

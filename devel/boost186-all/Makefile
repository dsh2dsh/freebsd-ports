PORTNAME=	boost186-all

USES=		metaport

COMMENT?=	The "meta-port" for boost libraries
WWW=		https://www.boost.org/

OPTIONS_DEFINE=	JAM LIBRARIES PYTHON DOCS
OPTIONS_DEFAULT=	JAM LIBRARIES
JAM_DESC=	Boost.Jam - Build tool from the boost.org
LIBRARIES_DESC=	Free portable C++ libraries
PYTHON_DESC=	Boost.Python - interfacing Python and C++

.include "common.mk"

LIBRARIES_RUN_DEPENDS=	${LOCALBASE}/lib/libboost_thread.so:devel/boost186-libs
JAM_RUN_DEPENDS=	${LOCALBASE}/bin/bjam:devel/boost186-jam
PYTHON_RUN_DEPENDS=	${LOCALBASE}/lib/${PY_BOOST}
PYTHON_USES=		python:env
DOCS_RUN_DEPENDS=	${LOCALBASE}/share/doc/boost/doc/html/index.html:devel/boost186-docs

.include <bsd.port.mk>

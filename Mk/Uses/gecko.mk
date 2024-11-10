.if ${.CURDIR:M*/www/firefox}
MOZ_OPTIONS+=	--allow-addon-sideload \
	--with-unsigned-addon-scopes=app,system \
	--disable-release
.endif

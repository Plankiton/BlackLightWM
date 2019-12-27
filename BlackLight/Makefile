# BlackLight - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c BlackLight.c util.c
OBJ = ${SRC:.c=.o}

all: options BlackLight

options:
	@echo "========================================"
	@echo BlackLight build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"
	@echo
	@echo "========================================"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

BlackLight: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}
	@echo
	@echo "========================================"
	@echo "CC -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f BlackLight ${OBJ} BlackLight-${VERSION}.tar.gz

dist: clean
	mkdir -p BlackLight-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
	    BlackLight.1 drw.h util.h ${SRC} BlackLight.png transient.c BlackLight-${VERSION}
	tar -cf BlackLight-${VERSION}.tar BlackLight-${VERSION}
	gzip BlackLight-${VERSION}.tar
	rm -rf BlackLight-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f BlackLight ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/BlackLight
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < BlackLight.1 > ${DESTDIR}${MANPREFIX}/man1/BlackLight.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/BlackLight.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/BlackLight\
	    ${DESTDIR}${MANPREFIX}/man1/BlackLight.1

.PHONY: all options clean dist install uninstall

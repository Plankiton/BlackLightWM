# BlackLight - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.c blacklight.c util.c
OBJ = ${SRC:.c=.o}

SRCT = drw.c blwm.c util.c
OBJT = ${SRC:.c=.o}

all: options BlackLight clean

options:
	@echo "========================================"
	@echo BlackLight build options:
	@echo "CC       = ${CC}"
	@echo
	@echo "CC -o $@ ${OBJ} ${LDFLAGS}"
	@echo "========================================"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

BlackLight: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

test: ${OBJT}
	${CC} -o $@ ${OBJT} ${LDFLAGS}

clean:
	rm -f config.h ${OBJ} BlackLight-${VERSION}.tar.gz

dist: clean
	mkdir -p BlackLight-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
	    drw.h util.h ${SRC} transient.c BlackLight-${VERSION}
	tar -cf BlackLight-${VERSION}.tar BlackLight-${VERSION}
	gzip BlackLight-${VERSION}.tar
	rm -rf BlackLight-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f BlackLight ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/BlackLight

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/BlackLight\
	    ${DESTDIR}${MANPREFIX}/man1/BlackLight.1

.PHONY: all options clean dist install uninstall

# blacklight - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = client.c drw.c blacklight.c util.c
OBJ = ${SRC:.c=.o}

all: options blacklight

options:
	@echo blacklight build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	${CC} -c ${CFLAGS} $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

blacklight: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f blacklight ${OBJ} blacklight-${VERSION}.tar.gz

dist: clean
	mkdir -p blacklight-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		blacklight.1 drw.h util.h ${SRC} blacklight.png transient.c blacklight-${VERSION}
	tar -cf blacklight-${VERSION}.tar blacklight-${VERSION}
	gzip blacklight-${VERSION}.tar
	rm -rf blacklight-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f blacklight ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/blacklight
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < blacklight.1 > ${DESTDIR}${MANPREFIX}/man1/blacklight.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/blacklight.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/blacklight\
		${DESTDIR}${MANPREFIX}/man1/blacklight.1

.PHONY: all options clean dist install uninstall

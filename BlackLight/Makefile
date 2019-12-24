# blwm - stereo window manager

include config.mk

SRC = client.c event.c blacklight.c util.c view.c
OBJ = ${SRC:.c=.o}

all: options blwm

options:
	@echo blwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: blwm.h config.h config.mk

config.h:
	@echo creating $@ from config.default.h
	@cp config.default.h $@

blwm: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}
	@strip $@

clean:
	@echo cleaning
	@rm -f blwm ${OBJ} blwm-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p blwm-${VERSION}
	@cp -R LICENSE Makefile README config.*.h config.mk \
	    blwm.1 blwm.h ${SRC} blwm-${VERSION}
	@tar -cf blwm-${VERSION}.tar blwm-${VERSION}
	@gzip blwm-${VERSION}.tar
	@rm -rf blwm-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f blwm ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/blwm
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${MANPREFIX}/man1
	@sed 's/VERSION/${VERSION}/g' < blwm.1 > ${DESTDIR}${MANPREFIX}/man1/blwm.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/blwm.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/blwm
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/blwm.1

.PHONY: all options clean dist install uninstall

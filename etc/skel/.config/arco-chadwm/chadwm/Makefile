# chadwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

# list source files
SRC = drw.c dwm.c util.c
# list object files
OBJ = ${SRC:.c=.o}

all: options chadwm

options:
	@echo chadwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

# defines how to compile .c files into .o files using specified compiler and compiler flags
.c.o:
	${CC} -c ${CFLAGS} $<

# Specifies that the object files depend on these two files
${OBJ}: config.h config.mk

# creates config.h from config.def.h if it does not exist
config.h:
	cp config.def.h $@

# The chadwm target builds the chadwm executable by linking the object files with the specified linker flags (LDFLAGS).
chadwm: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

# The clean target removes the chadwm executable, object files, and other generated files to clean up the build directory.
clean:
	rm -f chadwm ${OBJ} chadwm-${VERSION}.tar.gz config.h

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f chadwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/chadwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < chadwm.1 > ${DESTDIR}${MANPREFIX}/man1/chadwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/chadwm.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/chadwm\
		${DESTDIR}${MANPREFIX}/man1/chadwm.1

.PHONY: all options clean install uninstall

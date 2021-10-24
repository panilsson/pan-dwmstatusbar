# See LICENSE file for copyright and license details.

include config.mk

SRC = testwservice.c weather.c
OBJ = ${SRC:.c=.o}

all: options ${NAME}

options:
	@echo ${NAME} build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "GCC       = ${CC}"

.c.o:
	@echo GCC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

${NAME}: ${OBJ}
	@echo GCC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f testwservice testwservice.o weather.o ${NAME}-${VERSION}.tar.gz

.PHONY: all options clean dist install uninstall

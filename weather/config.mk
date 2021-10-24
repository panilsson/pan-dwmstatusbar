NAME = testwservice
VERSION = 1.0

# Customize below to fit your system

# paths
PREFIX = /usr
MANPREFIX = ${PREFIX}/share/man

CURLINC = /usr/local/include
CURLLIB = /usr/local/lib

# includes and libs
INCS = -I. -I/usr/include -I${CURLINC}
LIBS = -L/usr/lib -lc -L${CURLLIB} -lcurl -ljansson

# flags
CPPFLAGS = -DVERSION=\"${VERSION}\" -D_DEFAULT_SOURCE
CFLAGS = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS}
LDFLAGS = -g ${LIBS}

# compiler and linker
CC = gcc


CC=gcc
CFLAGS=-I.
DEPS = pokedex.h algorithms.h
PREFIX = /usr/local

all: options compile

options:
	@echo pokemon build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "CC       = ${CC}"

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compile: pokemon.o
	$(CC) -o pokemon pokemon.o

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f pokemon ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/pokemon

clean:
	rm -f pokemon *.o

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/pokemon
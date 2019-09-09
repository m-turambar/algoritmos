CC=g++
CFLAGS=-I.
DEPS = util.hpp

# $@ es un macro especial que simboliza
# el nombre del archivo antes del :

# $< es también un macro especial que
# representa el primer elemento de la
# lista de dependencias (aclarar)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hola: bfs.o
	$(CC) -o bfs bfs.o
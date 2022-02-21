CFLAGS = -g -Wall -Wextra -pedantic -Werror
CC = gcc

<<<<<<< HEAD
PROGRAMS = main_hash main_tests
=======
# PROGRAMS = main_tests
PROGRAMS = main_hash
>>>>>>> f3980f87c1646cb3c643da43eba52a141f289d2e


.PHONY:	all clean

all: $(PROGRAMS)

main_tests: main.o  entreeSortieLC.o biblioLC.o
	$(CC) -o $@ $(CFLAGS) $^

entreeSortieLC.o: entreeSortieLC.c
	$(CC) -c $(CFLAGS) entreeSortieLC.c 

biblioLC.o: biblioLC.c
	$(CC) -c $(CFLAGS) biblioLC.c

main_hash: mainHash.o  entreeSortieH.o biblioH.o
	$(CC) -o $@ $(CFLAGS) $^

entreeSortieH.o: entreeSortieH.c
	$(CC) -c $(CFLAGS) entreeSortieH.c 

biblioH.o: biblioH.c
	$(CC) -c $(CFLAGS) biblioH.c

clean:
	rm -f *.o *~ $(PROGRAMS)

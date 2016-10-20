#Winston Venderbush

GCC = gcc -g

all: list.o music_lib.o main.o
	$(GCC) list.o music_lib.o main.o -o prog

music_lib.o: music_lib.c music_lib.h list.h
	$(GCC) -c music_lib.c

list.o: list.c list.h
	$(GCC) -c list.c

main.o: main.c list.h
	$(GCC) -c main.c

clean:
	rm *.o
	rm *~

run: all
	./prog

debug: all
	gdb prog

GCC = gcc -g

all: music_lib.o list.o main.o
	$(GCC) music_lib.o list.o main.o -o prog

music_lib.o: music_lib.c music_lib.h
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
CC=gcc

default: program

main=script/main.c

font=src/*.c

options=-lpthread

program:
	$(CC) $(font) $(main) $(options) -o main.o
	./main.o # executando

clean:
	rm -f main.o
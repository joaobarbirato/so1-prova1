CC=gcc

default: program

main=script/main.c

font=src/*.c

program:
	$(CC) $(font) $(main) -o main.o
	./main.o

clean:
	rm -f main.o
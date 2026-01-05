all: compile

compile: abcsort.c bouble.c
	$(CC) -o ./bin/abcsort-linux-x64 abcsort.c -Wall -W -pedantic -std=c17

clean:
	rm ./bin/abcsort-linux-x64

all: compile

compile: abcsort.c bubble.c help.c sortio.c
	$(CC) -o ./bin/abcsort-linux-x64 abcsort.c bubble.c help.c sortio.c -Wall -W -pedantic -std=c17

clean:
	rm ./bin/abcsort-linux-x64

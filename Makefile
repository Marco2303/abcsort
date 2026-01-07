all: compile

compile: abcsort.c bubble.c help.c 
	$(CC) -o ./bin/abcsort-linux-x64 abcsort.c bubble.c help.c -Wall -W -pedantic -std=c17

clean:
	rm ./bin/abcsort-linux-x64

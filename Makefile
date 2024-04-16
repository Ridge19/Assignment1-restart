.default: all

all: Assignment1-s3934367

clean:
	rm -f Assignment1-s3934367 *.o

Assignment1-s3934367: board.o game.o helper.o player.o vacuumClean.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
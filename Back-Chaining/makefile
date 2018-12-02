CFLAGS = -std=c++11

all: main stdoutToFile

main: Expr.o
	g++ -o a main.cpp Expr.o $(CFLAGS)

Expr.o: Expr.cpp Expr.hpp
	g++ -c Expr.cpp $(CFLAGS)

stdoutToFile:
	g++ -o b stdoutToFile.cpp $(CFLAGS)

clean:
	rm a b *.o && wall -t 5 YEET

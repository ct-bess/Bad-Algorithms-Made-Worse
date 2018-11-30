CFLAGS = -std=c++11

all: main

main: Expr.o
	g++ -o a main.cpp Expr.o $(CFLAGS)

Expr.o: Expr.cpp Expr.hpp
	g++ -c Expr.cpp $(CFLAGS)

clean:
	rm a *.o && wall -t 5 YEET

FLAGS = -std=c++14

main: main.o funcs.o
	g++ -o main main.o funcs.o $(FLAGS)

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o $(FLAGS)


main.o: main.cpp funcs.h
	g++ -c main.cpp $(FLAGS)

funcs.o: funcs.cpp funcs.h
	g++ -c funcs.cpp $(FLAGS)

tests.o: tests.cpp funcs.h
	g++ -c tests.cpp $(FLAGS)

clean:
	rm funcs.o main.o tests.o main tests




#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and bst.o to executable main
main: main.o bst.o
	g++ -g -std=c++11 -o main main.o bst.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -std=c++11 -c main.cpp

#compile the bst.cpp to bst.o
bst.o: bst.cpp
	g++ -g -std=c++11 -c bst.cpp

#remove built files
clean:
	rm -rf main main.o bst.o *~

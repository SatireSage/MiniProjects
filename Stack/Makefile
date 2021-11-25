#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and stack.o to executable main
main: main.o stack.o
	g++ -g -std=c++17 -o main main.o stack.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -std=c++17 -c main.cpp

#compile the stack.cpp to stack.o
stack.o: stack.cpp
	g++ -g -std=c++17 -c stack.cpp

#remove built files
clean:
	rm -rf main main.o stack.o *~

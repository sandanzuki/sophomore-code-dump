all: BinaryTree.o main.o
	g++ -std=c++11 BinaryTree.o main.o -o main
BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -std=c++11 -c -g BinaryTree.cpp 
main.o: main.cpp BinaryTree.h
	g++ -std=c++11 -c -g main.cpp
clean:
	rm *.o main

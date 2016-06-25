main: main.o binarySearchTree.o binarySearchTreeII.o
	g++ -g -std=c++11 -o main main.o binarySearchTree.o binarySearchTreeII.o
binarySearch.o: binarySearchTree.cpp
	g++ -c -g -std=c++11 binarySearchTree.cpp
binarySearchII.o: binarySearchTreeII.cpp
	g++ -c -g -std=c++11 binarySearchTreeII.cpp
main.o: main.cpp
	g++ -c -g -std=c++11 main.cpp
clean:
	rm *.o main

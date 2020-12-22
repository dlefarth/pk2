main: main.cpp LinkedList.o
	g++ -o main main.cpp LinkedList.o ListIterator.o

LinkedList.o: LinkedList.cpp ListIterator.o
	g++ -c LinkedList.cpp

ListIterator.o: ListIterator.cpp
	g++ -c ListIterator.cpp

clean:
	rm LinkedList.o ListIterator.o main

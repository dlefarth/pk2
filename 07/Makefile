program: main.cpp bild.o audio.o medium.o
	g++ -o main main.cpp bild.o audio.o medium.o

bild.o: bild.cpp medium.o
	g++ -c bild.cpp medium.o

audio.o: audio.cpp medium.o
	g++ -c audio.cpp medium.o

medium.o: medium.cpp
	g++ -c medium.cpp
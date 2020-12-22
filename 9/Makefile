main: main.cpp audio.o bild.o
	g++ -o main main.cpp ../7/audio.o ../7/bild.o

bild.o: ../7/bild.cpp ../7/medium.o
        g++ -c ../7/bild.cpp ../7/medium.o

audio.o: ../7/audio.cpp ../7/medium.o
        g++ -c ../7/audio.cpp ../7/medium.o

medium.o: ../7/medium.cpp
        g++ -c ../7/medium.cpp         

clean:
	rm main
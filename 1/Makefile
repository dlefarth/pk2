main: libmy.a 
	gcc -o main main.c -L ./ -lmy -lm

libmy.a: printascii.o print_as_binary.o einmaleins.o 
	ar r libmy.a printascii.o print_as_binary.o einmaleins.o

printascii.o: printascii.c
	gcc -c printascii.c

print_as_binary.o: print_as_binary.c
	gcc -c print_as_binary.c

einmaleins.o: einmaleins.c
	gcc -c einmaleins.c

clean:
	rm main libmy.a printascii.o print_as_binary.o einmaleins.o 

all: main

main: ArvB.o ArvBplus.o frase.o ArvBplus.o main.c
	gcc main.c -o main ArvB.o ArvBplus.o frase.o 

    
ArvB.o: ArvB.c
	gcc -c ArvB.c

ArvBplus.o: ArvBplus.c
	gcc -c ArvBplus.c

frase.o: frase.c
	gcc -c frase.c

clean:
	rm -o


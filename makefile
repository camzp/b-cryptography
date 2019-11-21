all: main

main: ArvB.o frase.o letra.o main.c
	gcc main.c -o main ArvB.o frase.o letra.o
    
ArvB.o: ArvB.c
	gcc -c ArvB.c

frase.o: frase.c
	gcc -c frase.c

letra.o: letra.c
	gcc -c letra.c

clean:
	rm -o


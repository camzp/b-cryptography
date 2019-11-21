#include "frase.h"
#include <stdio.h>
#include <stdlib.h>


Frase iniciaFrase (int tamanho){
	Frase f;
	f.tamanho = tamanho;
	f.posicao = 0;
	f.letras = initLista();
	return f;
}

void toUpper(char *f){
	char * frase;
  frase = strtok(f,":");

  // Convert to upper case
  char *s = frase;
  while (*s) {
    *s = toupper((unsigned char) *s);
    s++;
  }
}

void leFrase (Frase *f){
    char texto[f->tamanho];
		// ver scanf
		toUpper(texto);

		for (int i=0; i < strlen(texto); ++i){
			if (texto[i] == 'A' || texto[i] == 'E' || texto[i] == 'I' 
						|| texto[i] == 'O'|| texto[i] == 'U'){
							insereFim(texto[i], 0, &f->letras);
							}
			else {
				insereFim(texto[i], 1, &f->letras);
			}
		}
		imprimeLista(f->letras); //debug
}


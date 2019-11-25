#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "frase.h"

Lista initLista (){
  Lista ini;
  ini = NULL;
  return ini;
}

int itsNull (Lista l){
	return (l == NULL);
}

void insereFim(char l, int c, Lista *li) {
	
	Letra *le;
	le = (Letra*) malloc (sizeof(Letra));
	le->letra = l ;
	le->classificacao = c;
	le->prox = NULL;

	if (itsNull (*li)){
		(*li) = le;
		return;
	}

	Letra *aux = (*li);
	//Enquanto o auxiliar, não achar vazio, ele vai para o próximo
	while (aux->prox != NULL) aux = aux->prox;
		//Inserindo no fim.
		aux->prox = le;
}

void imprimeLista (Lista l){
  Lista aux = l;
  while (aux != NULL){
    printf("%c\n", aux->letra);
    aux = aux -> prox;
  }  
}

void leFrase (Frase *f){
    char texto[f->tamanho];
		char temp;
		printf("Digite o texto: ");
		scanf("%c",&temp);
		fgets(texto,f->tamanho,stdin);
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
		// imprimeLista(f->letras); //debug
}

void removeLetra (Lista *l){
	Lista listaAux;
	if (itsNull(*l) == 1) return;
	//Copiar o ponteiro principal da lista
	listaAux = *l;	
	//Fazer o ponteiro principal da lista apontar pro próximo (novo primeiro elemento)
	(*l) = (*l)->prox;
	//Liberar a memória usando a cópia feita no ponteiro auxiliar
	free (listaAux);
	
}

Frase iniciaFrase (int tamanho){
	Frase f;
	f.tamanho = tamanho;
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

Lista retornaLetra (Frase *f){
	return f->letras;
}



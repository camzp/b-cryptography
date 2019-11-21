#include "letra.h"

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

char retornaLetra (Lista l) {
  return l->letra;
}

int retornaTipo(Lista l){
	return l->classificacao;
}

Lista prox (Lista l){
	return l->prox; 
}

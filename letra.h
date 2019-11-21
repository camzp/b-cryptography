#include <stdio.h>
#include <stdlib.h>

typedef struct letra {
  char letra;
  int classificacao;
  struct letra *prox;
} Letra;

typedef Letra* Lista;

Lista initLista();

int itsNull(Lista l);

void insereFim(char l, int c, Lista *li);

void imprimeLista (Lista l);

char retornaLetra (Lista l);

Letra mostraLetra (Lista l);

void removeLetra(Lista *l);

Lista prox (Lista l);



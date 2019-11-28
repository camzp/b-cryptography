#include <stdio.h>
#include <stdlib.h>
#include "string.h"


#ifndef FRASE_H
#define FRASE_H


typedef struct letra {
  char letra;
  int classificacao; //0: VOGAL, 1: CONSOANTE
  struct letra *prox;
} Letra;

typedef Letra* Lista;

typedef struct frase {
   Lista letras;
   int tamanho;
} Frase;

Lista initLista ();

int itsNull (Lista l);

void insereFim(char l, Lista *li);

void imprimeLista (Lista l);

void leFrase (Frase *f);

Lista retornaLetra (Frase *f);


Lista prox (Lista l);

void removeLetra (Lista *l);

Frase iniciaFrase (int tamanho);

void toUpper(char *f);

#endif

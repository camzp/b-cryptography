#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#ifndef LETRA_H
#define LETRA_H

typedef struct letra
{
  char letra;
  int classificacao; //0: VOGAL, 1: CONSOANTE
  struct letra *prox;
} Letra;

typedef Letra *Lista;

Lista initLista();

int itsNull(Lista l);

void insereFim(char l, int c, Lista *li);

void imprimeLista(Lista l);

char retornaLetra(Lista l);

int retornaTipo(Lista l);

Lista prox(Lista l);

#endif

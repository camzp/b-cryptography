#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "letra.h"


typedef struct frase {
   Lista letras;
   int posicao;
   int tamanho;
} Frase;

Frase iniciaFrase(int tamanho);

void editaTamanhoFrase(int tamanho);

void toUpper(char *f);

void leFrase(Frase *f);

void terminaFrase(Frase *f);
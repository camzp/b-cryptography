#include <stdio.h>
#include <stdlib.h>
#include "letras.h"


typedef struct frase {
   Lista letras;
   int posicao;
   int tamanho;
} Frase;

Frase iniciaFrase (int tamanho);

void leFrase (Frase *f);

void proximaLetra (Frase *f);

void terminaFrase (Frase *f);
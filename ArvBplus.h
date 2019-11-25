#include "frase.h"

#ifndef ARVBP_H
#define ARVBP_H

typedef struct ArvBP
{
  int nchaves, folha, nivel;
  Letra *l;
  struct ArvBP **filho, *prox;
} TABM;

//Cria uma nova página
TABM *Cria(int t);

//Libera a página
TABM *Libera(TABM *a);

//Imprime a árvore
void imprime(TABM *a, int andar);

TABM *busca(TABM *a, char mat);

TABM *Inicializa();

TABM *divisao(TABM *x, int i, TABM *y, int t);

TABM *insere_nao_completo(TABM *x, char mat, int t);

//Inserção de Letras
TABM *insere(TABM *T, char mat, int t);

void buscaClassificacao(TABM *a, char *nome, int andar);

#endif
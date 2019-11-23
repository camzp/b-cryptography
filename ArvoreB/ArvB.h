#include "../letra.h"

#ifndef ARVB_H
#define ARVB_H

typedef struct ArvB
{
  int nchaves, folha, nivel;
  Letra *l;
  struct ArvB **filho;
} TAB;

//Cria uma nova página
TAB *Cria(int t);

//Libera a página
TAB *Libera(TAB *a);

//Imprime a árvore
void Imprime(TAB *a, int andar);

TAB *Busca(TAB *x, char ch);

TAB *Inicializa();

TAB *Divisao(TAB *x, int i, TAB *y, int t);

TAB *Insere_Nao_Completo(TAB *x, char k, int t);

//Inserção de Letras
TAB *Insere(TAB *T, char k, int t);

TAB *remover(TAB *arv, char ch, int t);

TAB *retira(TAB *arv, int k, int t);

#endif
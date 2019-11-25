#include "frase.h"
#ifndef ARVB_H
#define ARVB_Hclea

typedef struct ArvB
{
  int nchaves, folha, nivel;
  Letra *l;
  struct ArvB **filho;
} TAB;

//Cria uma nova página
TAB *CriaB(int t);

//Libera a página
TAB *LiberaB(TAB *a);

//Imprime a árvore
void ImprimeB(TAB *a, int andar);

TAB *BuscaB(TAB *x, char ch);

TAB *InicializaB();

TAB *DivisaoB(TAB *x, int i, TAB *y, int t);

TAB *Insere_Nao_CompletoB(TAB *x, char k, int t);

//Inserção de Letras
TAB *InsereB(TAB *T, char k, int t);

TAB *removerB(TAB *arv, char ch, int t);

TAB *retiraB(TAB *arv, char k, int t);

void buscaClassificacao(TAB *a, char *nome, int andar);

void removeClassificacao(TAB *a, char *nome, int andar);

#endif
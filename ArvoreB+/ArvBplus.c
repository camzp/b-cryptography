#include <stdio.h>
#include <stdlib.h>
#include "ArvBplus.h"
#include "../letra.h"

const int t = 2;

//Cria uma nova página
TABM *Cria(int t)
{
  TABM *novo = (TABM *)malloc(sizeof(TABM));
  novo->nchaves = 0;
  novo->l = (Letra *)malloc(sizeof(Letra) * ((t * 2) - 1));
  novo->l->classificacao = 0;
  novo->folha = 1;
  novo->nivel = 0;
  novo->prox = NULL;
  novo->filho = (TABM **)malloc(sizeof(TABM *) * (t * 2));
  int i;
  for (i = 0; i < (t * 2); i++)
    novo->filho[i] = NULL;
  return novo;
}

//Libera a página
TABM *Libera(TABM *a)
{
  if (a)
  {
    if (!a->folha)
    {
      int i;
      for (i = 0; i <= a->nchaves; i++)
        Libera(a->filho[i]);
    }
    free(a->l);
    free(a);
    return NULL;
  }
}

//Imprime a árvore
void imprime(TABM *a, int andar)
{
  if (a)
  {
    int i, j;
    for (i = 0; i <= a->nchaves - 1; i++)
    {
      imprime(a->filho[i], andar + 1);
      for (j = 0; j <= andar; j++)
        printf("   ");
      printf("%c\n", a->l[i].letra);
    }
    imprime(a->filho[i], andar + 1);
  }
}

TABM *busca(TABM *a, char mat)
{
  if (!a)
    return NULL;
  int i = 0;
  while ((i < a->nchaves) && (mat != a->l[i].letra))
    i++;
  if ((i < a->nchaves) && (a->folha) && (mat == a->l[i].letra))
    return a;
  if (a->folha)
    return NULL;
  if (a->l[i].letra == mat)
    i++;
  return busca(a->filho[i], mat);
}

TABM *Inicializa()
{
  return NULL;
}

TABM *divisao(TABM *x, int i, TABM *y, int t)
{
  TABM *z = Cria(t);
  z->folha = y->folha;
  int j;
  if (!y->folha)
  {
    z->nchaves = t - 1;
    for (j = 0; j < t - 1; j++)
      z->l[j] = y->l[j + t];
    for (j = 0; j < t; j++)
    {
      z->filho[j] = y->filho[j + t];
      y->filho[j + t] = NULL;
    }
  }
  else
  {
    z->nchaves = t;
    for (j = 0; j < t; j++)
      z->l[j] = y->l[j + t - 1]; //Caso em que y � folha, temos q passar a info para o n� da direita
    y->prox = z;
  }
  y->nchaves = t - 1;
  for (j = x->nchaves; j >= i; j--)
    x->filho[j + 1] = x->filho[j];
  x->filho[i] = z;
  for (j = x->nchaves; j >= i; j--)
    x->l[j] = x->l[j - 1];
  x->l[i - 1] = y->l[t - 1];
  x->nchaves++;
  return x;
}

TABM *insere_nao_completo(TABM *x, char mat, int t)
{
  int i = x->nchaves - 1;
  if (x->folha)
  {
    while ((i >= 0) && (mat != x->l[i].letra))
    {
      x->l[i + 1] = x->l[i];
      i--;
    }
    x->l[i + 1].letra = mat;
    x->nchaves++;
    return x;
  }
  while ((i >= 0) && (mat != x->l[i].letra))
    i--;
  i++;
  if (x->filho[i]->nchaves == ((2 * t) - 1))
  {
    x = divisao(x, (i + 1), x->filho[i], t);
    if (mat != x->l[i].letra)
      i++;
  }
  x->filho[i] = insere_nao_completo(x->filho[i], mat, t);
  return x;
}

//Inserção de Letra
TABM *insere(TABM *T, char mat, int t)
{
  if (busca(T, mat))
    return T;
  if (!T)
  {
    T = Cria(t);
    T->l[0].letra = mat;
    T->nchaves = 1;
    return T;
  }
  if (T->nchaves == (2 * t) - 1)
  {
    TABM *S = Cria(t);
    S->nchaves = 0;
    S->folha = 0;
    S->filho[0] = T;
    S = divisao(S, 1, T, t);
    S = insere_nao_completo(S, mat, t);
    return S;
  }
  T = insere_nao_completo(T, mat, t);
  return T;
}
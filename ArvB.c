#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"

const int t = 2;

//Cria uma nova página
TAB *Cria(int t)
{
  TAB *novo = (TAB *)malloc(sizeof(TAB));
  novo->nchaves = 0;
  novo->l = (Letras *)malloc(sizeof(Letras) * ((t * 2) - 1));
  novo->l->classificacao = 0;
  novo->folha = 1;
  novo->nivel = 0;
  novo->filho = (TAB **)malloc(sizeof(TAB *) * (t * 2));
  int i;
  for (i = 0; i < (t * 2); i++)
    novo->filho[i] = NULL;
  return novo;
}

//Libera a página
TAB *Libera(TAB *a)
{
  if (a)
  {
    if (a->folha == 0)
    {
      int i;
      for (i = 0; i < a->nchaves; i++)
        Libera(a->filho[i]);
    }
    free(a->l);
    free(a->filho);
    free(a);
    return NULL;
  }
}

//Imprime a árvore
void Imprime(TAB *a, int andar)
{
  if (a)
  {
    int i, j;
    for (i = 0; i <= a->nchaves - 1; i++)
    {
      Imprime(a->filho[i], andar + 1);
      for (j = 0; j <= andar; j++)
        printf("   ");
      //printf("%d\n", a->chave[i]);
      printf("%c\n", a->l[i].letra);
    }
    Imprime(a->filho[i], andar + 1);
  }
}

TAB *Busca(TAB *x, char ch)
{
  TAB *resp = NULL;
  if (!x)
    return resp;

  int i = 0;
  while ((i < x->nchaves) && (ch != x->l[i].letra))
    i++;
  if ((i < x->nchaves) && (ch == x->l[i].letra))
    return x;
  if (x->folha == 1)
    return resp;
  return Busca(x->filho[i], ch);
}

TAB *Inicializa()
{
  return NULL;
}

TAB *Divisao(TAB *x, int i, TAB *y, int t)
{
  TAB *z = Cria(t);
  z->nchaves = t - 1;
  z->folha = y->folha;
  int j;
  for (j = 0; j < t - 1; j++)
    z->l[j] = y->l[j + t];
  if (!y->folha)
  {
    for (j = 0; j < t; j++)
    {
      z->filho[j] = y->filho[j + t];
      y->filho[j + t] = NULL;
    }
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

TAB *Insere_Nao_Completo(TAB *x, char k, int t)
{
  int i = x->nchaves - 1;
  if (x->folha)
  {
    while ((i >= 0) && (k != x->l[i].letra))
    {
      x->l[i + 1] = x->l[i];
      i--;
    }
    x->l[i + 1].letra = k;
    x->nchaves++;
    return x;
  }
  while ((i >= 0) && (k != x->l[i].letra))
    i--;
  i++;
  if (x->filho[i]->nchaves == ((2 * t) - 1))
  {
    x = Divisao(x, (i + 1), x->filho[i], t);
    if (k != x->l[i].letra)
      i++;
  }
  x->filho[i] = Insere_Nao_Completo(x->filho[i], k, t);
  return x;
}

//Inserção de Letras
TAB *Insere(TAB *T, char k, int t)
{
  if (Busca(T, k))
    return T;
  if (!T)
  {
    T = Cria(t);
    T->l[0].letra = k;
    T->nchaves = 1;
    return T;
  }
  if (T->nchaves == (2 * t) - 1)
  {
    TAB *S = Cria(t);
    S->nchaves = 0;
    S->folha = 0;
    S->filho[0] = T;
    S = Divisao(S, 1, T, t);
    S = Insere_Nao_Completo(S, k, t);
    return S;
  }
  T = Insere_Nao_Completo(T, k, t);
  return T;
}

TAB *remover(TAB *arv, char ch, int t)
{
  if (!arv)
    return arv;
  int i;

  for (i = 0; i < arv->nchaves && arv->l[i].letra != ch; i++)
    ;
  if (i < arv->nchaves && ch == arv->l[i].letra)
  { //CASOS 1, 2A, 2B e 2C
    if (arv->folha)
    { //CASO 1
      int j;
      for (j = i; j < arv->nchaves - 1; j++)
        arv->l[j] = arv->l[j + 1];
      arv->nchaves--;
      return arv;
    }
    if (!arv->folha && arv->filho[i]->nchaves >= t)
    { //CASO 2A
      TAB *y = arv->filho[i];
      while (!y->folha)
        y = y->filho[y->nchaves];
      char temp = y->l[y->nchaves - 1].letra;
      arv->filho[i] = remover(arv->filho[i], temp, t);
      arv->l[i].letra = temp;
      return arv;
    }
    if (!arv->folha && arv->filho[i + 1]->nchaves >= t)
    { //CASO 2B
      TAB *y = arv->filho[i + 1];
      while (!y->folha)
        y = y->filho[0];
      char temp = y->l[0].letra;
      y = remover(arv->filho[i + 1], temp, t);
      arv->l[i].letra = temp;
      return arv;
    }
    if (!arv->folha && arv->filho[i + 1]->nchaves == t - 1 && arv->filho[i]->nchaves == t - 1)
    { //CASO 2C
      TAB *y = arv->filho[i];
      TAB *z = arv->filho[i + 1];
      y->l[y->nchaves].letra = ch;
      int j;
      for (j = 0; j < t - 1; j++)
        y->l[t + j] = z->l[j];
      for (j = 0; j <= t; j++)
        y->filho[t + j] = z->filho[j];
      y->nchaves = 2 * t - 1;
      for (j = i; j < arv->nchaves - 1; j++)
        arv->l[j] = arv->l[j + 1];
      for (j = i + 1; j <= arv->nchaves; j++)
        arv->filho[j] = arv->filho[j + 1];
      arv->filho[j] = NULL;
      arv->nchaves--;
      arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;
    }
  }

  TAB *y = arv->filho[i], *z = NULL;
  if (y->nchaves == t - 1)
  { //CASOS 3A e 3B
    if ((i < arv->nchaves) && (arv->filho[i + 1]->nchaves >= t))
    { //CASO 3A
      z = arv->filho[i + 1];
      y->l[t - 1] = arv->l[i];
      y->nchaves++;
      arv->l[i] = z->l[0];
      int j;
      for (j = 0; j < z->nchaves - 1; j++)
        z->l[j] = z->l[j + 1];
      y->filho[y->nchaves] = z->filho[0];
      for (j = 0; j < z->nchaves; j++)
        z->filho[j] = z->filho[j + 1];
      z->nchaves--;
      arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;
    }
    if ((i > 0) && (!z) && (arv->filho[i - 1]->nchaves >= t))
    { //CASO 3A
      z = arv->filho[i - 1];
      int j;
      for (j = y->nchaves; j > 0; j--)
        y->l[j] = y->l[j - 1];
      for (j = y->nchaves + 1; j > 0; j--)
        y->filho[j] = y->filho[j - 1];
      y->l[0] = arv->l[i - 1];
      y->nchaves++;
      arv->l[i - 1] = z->l[z->nchaves - 1];
      y->filho[0] = z->filho[z->nchaves];
      z->nchaves--;
      arv->filho[i] = remover(y, ch, t);
      return arv;
    }
    if (!z)
    { //CASO 3B
      if (i < arv->nchaves && arv->filho[i + 1]->nchaves == t - 1)
      {
        z = arv->filho[i + 1];
        y->l[t - 1] = arv->l[i];
        y->nchaves++;
        int j;
        for (j = 0; j < t - 1; j++)
        {
          y->l[t + j] = z->l[j];
          y->nchaves++;
        }
        if (!y->folha)
        {
          for (j = 0; j < t; j++)
          {
            y->filho[t + j] = z->filho[j];
          }
        }
        for (j = i; j < arv->nchaves - 1; j++)
        {
          arv->l[j] = arv->l[j + 1];
          arv->filho[j + 1] = arv->filho[j + 2];
        }
        arv->nchaves--;
        arv = remover(arv, ch, t);
        return arv;
      }
      if ((i > 0) && (arv->filho[i - 1]->nchaves == t - 1))
      {
        z = arv->filho[i - 1];
        if (i == arv->nchaves)
          z->l[t - 1] = arv->l[i - 1];
        else
          z->l[t - 1] = arv->l[i];
        z->nchaves++;
        int j;
        for (j = 0; j < t - 1; j++)
        {
          z->l[t + j] = y->l[j];
          z->nchaves++;
        }
        if (!z->folha)
        {
          for (j = 0; j < t; j++)
          {
            z->filho[t + j] = y->filho[j];
          }
        }
        arv->nchaves--;
        arv->filho[i - 1] = z;
        arv = remover(arv, ch, t);
        return arv;
      }
    }
  }
  arv->filho[i] = remover(arv->filho[i], ch, t);
  return arv;
}

TAB *retira(TAB *arv, int k, int t)
{
  if (!arv || !Busca(arv, k))
    return arv;
  return remover(arv, k, t);
}
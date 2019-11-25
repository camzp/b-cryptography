#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"
#include "ArvBplus.h"

int main()
{
  //Inicialização de Variaveis.
  TAB *arvoreB = InicializaB();
  TABM *arvoreBM = Inicializa();
  char a;
  for(a='A';a!='Z';a++) printf("%c ",a);
  int d; //Ordem
  int tamanho;
  printf("********** Criptografia de Árvores B e B+ **********\n\n");
  printf("Digite a ordem das árvores: ");
  scanf ("%d", &d);
  printf("\nDigite o tamanho da frase: ");
  scanf ("%d", &tamanho);
  // texto = iniciaFrase(tamanho);
  // leFrase(&texto);
  // Lista atual = initLista();
  // atual = retornaLetra(&texto);
  // Lista aux = atual;
  // while (aux != NULL){
  //   arvoreB  = InsereB(arvoreB , aux->letra, d);
  //   arvoreBM = insere(arvoreBM , aux->letra, d);
  //   printf("*** LETRA ADICIONADA: %c ***", aux->letra);
  //   aux = aux -> prox;
  // }  
  // printf("*** Impressão da Árvore B + ***");
  // imprime(arvoreBM, 0);
  // printf("*** Impressão da Árvore B ***");
  // ImprimeB(arvoreB, 0);
}   
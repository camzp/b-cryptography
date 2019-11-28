#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"
#include "ArvBplus.h"

int main()
{
  TAB *arvoreB = InicializaB();
  TABM *arvoreBM = Inicializa();
  Frase texto;
  Lista aux;
  int d; //Ordem
  int tamanho;
  int again = 1;

  printf("*** *** *** Criptografia de Árvores B e B+ *** *** ***\n\n");
  printf("Digite a ordem das árvores: ");
  scanf("%d", &d);
  printf("\nDigite o tamanho da frase: ");
  scanf("%d", &tamanho);
  texto = iniciaFrase(tamanho);
  leFrase(&texto);
  aux = retornaLetra(&texto);
  while (aux != NULL)
  {
    if (aux->letra != '\0' || aux->letra != ' ')
    {
      arvoreB = InsereB(arvoreB, aux->letra, d);
      arvoreBM = insere(arvoreBM, aux->letra, d);
    }
    aux = aux->prox;
  }

  printf("***  Impressão da Árvore B + ***\n");
  imprime(arvoreBM, 0);
  printf("*** Impressão da Árvore B *** \n");
  ImprimeB(arvoreB, 0);
  printf("\n");

  int resposta;
  char chave;
  char vogal[6] = "vogal";
  char consoante[10] = "consoante";

  while (again != 0){

    printf ("0 - Buscar Vogais \n");
    printf ("1 - Buscar Consoantes \n");
    printf ("2 - Remover Vogais \n");
    printf ("3 - Remover Consoantes\n");
    printf ("4 - Imprimir Árvores \n");
    printf ("5 - Retirar Elementos \n");
    printf ("6 - Sair \n");
  
    scanf("%d", &resposta);
    
    switch (resposta){

    case 0:
      printf("*** Impressão da Árvore B *** \n");
      buscaClassificacaoB(arvoreB, vogal, 0);
      printf("\n");
      printf("***  Impressão da Árvore B + ***\n");
      buscaClassificacao(arvoreBM, vogal, 0);
      printf("\n");
    break;
    
    case 1:
      printf("*** Impressão da Árvore B *** \n");
      buscaClassificacaoB(arvoreB, consoante, 0);
      printf("\n");
      printf("***  Impressão da Árvore B + ***\n");
      buscaClassificacao(arvoreBM, consoante, 0);
      printf("\n"); 
    break;

    case 2:
      printf("*** Impressão da Árvore B *** \n");
      removeClassificacaoB(arvoreB, vogal, 0);
      printf("\n");
    break;

    case 3:
      printf("*** Impressão da Árvore B *** \n");
      removeClassificacaoB(arvoreB, consoante, 0);
      printf("\n");
    break;

    case 4:
      printf("***  Impressão da Árvore B + ***\n");
      imprime(arvoreBM, 0);
      printf("*** Impressão da Árvore B *** \n");
      ImprimeB(arvoreB, 0);
    break;

    case 5:
      printf("Digite a chave a ser retirada: ");
      scanf(" %c", &chave);
      printf("\n");
      retiraB(arvoreB, chave, d);
    break;

    case 6:
      again = 0;
    break;

    
    default:
      printf ("0 - Buscar Vogais \n");
      printf ("1 - Buscar Consoantes \n");
      printf ("2 - Remover Vogais \n");
      printf ("3 - Remover Consoantes\n");
      printf ("4 - Remover Letra \n");
      printf ("5 - Retirar Elementos \n");
      printf ("6 - Sair \n");
      scanf("%d", &resposta);
    }


  }
}

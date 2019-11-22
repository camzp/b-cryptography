#include <stdio.h>
#include <stdlib.h>
#include "ArvBplus.h"

int main()
{
  const int t = 2;
  TABM *arvore = Inicializa();
  int num = 0, to;
  char ch, from;
  while (num != -1)
  {
    printf("Digite 1 para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%i", &num);
    fflush(stdin);
    // if (num == -9)
    // {
    //   scanf("\n%c", &from);
    //   arvore = retira(arvore, from, t);
    //   imprime(arvore, 0);
    // }
    if (num == -1)
    {
      printf("\n");
      imprime(arvore, 0);
      Libera(arvore);
      return 0;
    }
    else if (!num)
    {
      printf("\n");
      imprime(arvore, 0);
    }
    else if (num == 1)
    {
      printf("Digite um caracter: ");
      scanf("\n%c", &ch);
      arvore = insere(arvore, ch, t);
    }

    printf("\n\n");
  }
}
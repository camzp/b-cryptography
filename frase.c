#include "frase.h"
#include <stdio.h>
#include <stdlib.h>


Frase iniciaFrase (int tamanho);
	Frase f;
	f->tamanho = tamanho;
	f->posicao = 0;
	f->letras = initLista();
	return f;
}

void leFrase (Frase *f){
  
}
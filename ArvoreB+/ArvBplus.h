typedef struct letras
{
  char letra;
  int classificacao;
} Letras;

typedef struct ArvB
{
  int nchaves, folha, nivel;
  Letras *l;
  struct ArvB **filho, *prox;
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
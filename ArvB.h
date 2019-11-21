typedef struct ArvB
{
  int nchaves, folha, nivel;
  char *chave;
  struct ArvB **filho;
} TAB;

//Cria uma nova página
TAB *Cria(int t);

//Libera a página
TAB *Libera(TAB *a);

//Imprime a árvore
void Imprime(TAB *a, int andar);

//Busca uma letra
TAB *Busca(TAB *x, int ch);

//Inicializa
TAB *Inicializa();

TAB *Divisao(TAB *x, int i, TAB *y, int t);
TAB *Insere_Nao_Completo(TAB *x, int k, int t);
TAB *Insere(TAB *T, int k, int t);
TAB *remover(TAB *arv, int ch, int t);
TAB *retira(TAB *arv, int k, int t);
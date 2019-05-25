#define N 50 /* número máximo de elementos */
typedef struct pilha
{
  int n;        /* vet[n]: primeira posição livre do vetor */
  float vet[N]; /* vet[n-1]: topo da pilha */
  /* vet[0] a vet[N-1]: posições ocupáveis */
} Pilha;

void pilha_push(Pilha *p, float v);
int pilha_vazia(Pilha *p);
float pilha_pop(Pilha *p);
void pilha_libera(Pilha *p);
#define N 100 /* número máximo de elementos */
typedef struct fila
{
  int n;   /* número de elementos na fila */
  int ini; /* posição do próximo elemento a ser retirado da fila */
  float vet[N];
} Fila;

Fila *fila_cria(void)
{
  Fila *f = (Fila *)malloc(sizeof(Fila));
  f->n = 0;   /* inicializa fila como vazia */
  f->ini = 0; /* escolhe uma posição inicial */
  return f;
}

void fila_insere(Fila *f, float v)
{
  int fim;
  if (f->n == N)
  { /* fila cheia: capacidade esgotada */
    printf("Capacidade da fila estourou.\n");
    exit(1); /* aborta programa */
  }
  /* insere elemento na próxima posição livre */
  fim = (f->ini + f->n) % N;
  f->vet[fim] = v;
  f->n++;
  printf("\n\tElemento %.2f foi inserido na posicao %d. Fila possui agora %d elementos\n", v, fim, f->n);
}

int fila_vazia(Fila *f)
{
  return (f->n == 0);
}

float fila_retira(Fila *f)
{
  float v;
  if (fila_vazia(f))
  {
    printf("Fila vazia.\n");
    exit(1); /* aborta programa */
  }
  /* retira elemento do início */
  v = f->vet[f->ini];
  f->ini = (f->ini + 1) % N;
  f->n--;
  return v;
}

void fila_libera(Fila *f)
{
  free(f);
}
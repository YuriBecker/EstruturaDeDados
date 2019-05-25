#define N 5
typedef struct fila2
{
  int n;
  int ini;
  float vet[N];
} Fila2;

Fila2 *fila2_cria(void);
int fila2_vazia(Fila2 *f);
void fila2_libera(Fila2 *f);
void fila2_insere_ini(Fila2 *f, float v);
void fila2_insere_fim(Fila2 *f, float v);
void imprime_fila2(Fila2 *f);
float fila2_retira_fim(Fila2 *f);
float fila2_retira_ini(Fila2 *f);

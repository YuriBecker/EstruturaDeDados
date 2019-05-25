/* nó da lista para armazenar valores reais */
struct lista
{
  float info;
  struct lista *prox;
};
typedef struct lista Lista;

/* estrutura da fila */
typedef struct fila
{
  Lista *ini;
  Lista *fim;
} Fila;

Fila *fila_cria(void);
int fila_vazia(Fila *f);
void fila_insere(Fila *f, float v);
float fila_retira(Fila *f);
void fila_libera(Fila *f);
/* nó da lista para armazenar valores reais */
typedef struct lista
{
  float info;
  struct lista *prox;
} Lista;
typedef struct lista Lista;
/* estrutura da pilha */
typedef struct pilha
{
  Lista *prim; /* aponta para o topo da pilha */
} Pilha;

Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
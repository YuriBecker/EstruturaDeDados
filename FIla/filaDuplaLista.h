/* nó da lista para armazenar valores reais */
struct lista2
{
  float info;
  struct lista2 *ant;
  struct lista2 *prox;
};
typedef struct lista2 Lista2;
/* estrutura da fila */
struct fila2
{
  Lista2 *ini;
  Lista2 *fim;
};
typedef struct fila2 Fila2;

Fila2 *fila2_cria(void);
void fila2_libera(Fila2 *f);
Lista2 *ins2_ini(Lista2 *ini, float v);
void fila2_insere_ini(Fila2 *f, float v);
void fila2_imprime(Fila2 *f);
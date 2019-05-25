/* Definição dos tipos de objetos */
#define RET 0
#define TRI 1
#define CIR 2
/* Definição do nó da estrutura */
struct listahet
{
  int tipo;
  void *info;
  struct listahet *prox;
};
typedef struct listahet ListaHet;
struct retangulo
{
  float b;
  float h;
};
typedef struct retangulo Retangulo;
struct triangulo
{
  float b;
  float h;
};
typedef struct triangulo Triangulo;
struct circulo
{
  float r;
};
typedef struct circulo Circulo;
ListaHet *cria_ret(ListaHet *l, float b, float h);
ListaHet *cria_tri(ListaHet *l, float b, float h);
ListaHet *cria_cir(ListaHet *l, float r);
void lst_imprime(ListaHet *l);
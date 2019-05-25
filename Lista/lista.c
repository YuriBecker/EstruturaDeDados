#include "lista.h"

Lista *createL(void)
{
  return NULL;
}

Lista *insertL(Lista *lista, int num)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = num;
  novo->prox = lista;
  return novo;
}

void showL(Lista *lista)
{
  Lista *pontAux;
  printf("\n\nInformacoes da lista:\n\n");
  for (pontAux = lista; pontAux != NULL; pontAux = pontAux->prox)
    printf("info = % d\n", pontAux->info);
}

bool isEmptyL(Lista *lista)
{
  if (lista == NULL)
    return true;
  return false;
}

Lista *searchL(Lista *lista, int value)
{
  Lista *pontAux;
  for (pontAux = lista; pontAux != NULL; pontAux = pontAux->prox)
  {
    if (pontAux->info == value)
    {
      printf("\nElemento %d foi encontrado no endereco %p", pontAux->info, pontAux);
      return pontAux;
    }
  }
  return NULL;
}

Lista *removeL(Lista *lista, int value)
{
  Lista *ant = NULL;      /* ponteiro para elemento anterior */
  Lista *pontAux = lista; /* ponteiro para percorrer a lista */
  /* procura elemento na lista, guardando anterior */
  while (pontAux != NULL && pontAux->info != value)
  {
    ant = pontAux;
    pontAux = pontAux->prox;
  }
  /* verifica se achou elemento */
  if (pontAux == NULL)
    return lista; /* não achou: retorna lista original */
  /* retira elemento */
  if (ant == NULL)
  { /* retira elemento do inicio */
    lista = pontAux->prox;
  }
  else
  { /* retira elemento do meio da lista */
    ant->prox = pontAux->prox;
  }
  free(pontAux);
  return lista;
}

Lista *freeL(Lista *lista)
{
  Lista *pontAux = lista;
  while (pontAux != NULL)
  {
    lista = pontAux->prox; /* guarda referência pontAux/ próx. elemento */
    printf("\nO elemento a ser liberado eh o %d no end %pontAux\n", pontAux->info, pontAux);
    free(pontAux);   /* libera a memória apontada por pontAux */
    pontAux = lista; /* faz pontAux apontar para o próximo */
  }
  return NULL; //ou return pontAux ou return lista
}

Lista *insertOrderlyL(Lista *lista, int value)
{
  Lista *novo;
  Lista *ant = NULL;      /* ponteiro para elemento anterior */
  Lista *pontAux = lista; /* ponteiro para percorrer a lista */
  /* procura posição de inserção */
  while (pontAux != NULL && pontAux->info < value)
  {
    ant = pontAux;
    pontAux = pontAux->prox;
  }
  /* cria novo elemento */
  novo = (Lista *)malloc(sizeof(Lista));
  novo->info = value;
  /* encadeia elemento */
  if (ant == NULL)
  { /* insere elemento no início */
    novo->prox = lista;
    lista = novo;
  }
  else
  { /* insere elemento no meio da lista */
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  return lista;
}

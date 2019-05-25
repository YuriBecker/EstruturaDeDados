#include "listadupla.h"

ListaD *insertL2(ListaD *lista, int value)
{
  ListaD *novo = (ListaD *)malloc(sizeof(ListaD));
  novo->info = value;
  novo->prox = lista;
  novo->ant = NULL;
  /* verifica se lista não estava vazia */
  if (lista != NULL)
    lista->ant = novo;
  return novo;
}

ListaD *createL2(void)
{
  return NULL;
}

/* função imprime: imprime valores dos elementos */
void showL2(ListaD *lista)
{
  ListaD *pontAux;
  printf("\n\nInformacoes da lista:\n\n");
  for (pontAux = lista; pontAux != NULL; pontAux = pontAux->prox)
    printf("info = %d\n", pontAux->info);
}

ListaD *searchL2(ListaD *lista, int value)
{
  ListaD *pontAux;
  for (pontAux = lista; pontAux != NULL; pontAux = pontAux->prox)
  {
    if (pontAux->info == value)
    {
      printf("\nElemento %d foi encontrado no endereco %pontAux", pontAux->info, pontAux);
      return pontAux;
    }
  }
  return NULL;
}

ListaD *removeL2(ListaD *lista, int value)
{
  ListaD *pontAux = searchL2(lista, value);
  if (pontAux == NULL)
    return lista; /* não achou o elemento: retorna lista inalterada */
  /* retira elemento do encadeamento */
  if (lista == pontAux) /* testa se é o primeiro elemento */
    lista = pontAux->prox;
  else
    pontAux->ant->prox = pontAux->prox;
  if (pontAux->prox != NULL) /* testa se é o último elemento */
    pontAux->prox->ant = pontAux->ant;
  free(pontAux);
  return lista;
}

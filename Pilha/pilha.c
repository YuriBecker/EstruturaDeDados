#include <stdlib.h>
#include "pilha.h"

Pilha *pilha_cria(void)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->prim = NULL;
  return p;
}

void pilha_push(Pilha *p, float v)
{
  Lista *n = (Lista *)malloc(sizeof(Lista));
  n->info = v;
  n->prox = p->prim;
  p->prim = n;
}

float pilha_pop(Pilha *p)
{
  Lista *t;
  float v;
  if (pilha_vazia(p))
  {
    printf("Pilha vazia.\n");
    exit(1);
  } /* aborta programa */
  t = p->prim;
  v = t->info;
  p->prim = t->prox;
  free(t);
  return v;
}

void pilha_libera(Pilha *p)
{
  Lista *q = p->prim;
  while (q != NULL)
  {
    Lista *t = q->prox;
    free(q);
    q = t;
  }
  free(p);
}
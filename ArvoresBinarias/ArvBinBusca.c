#include "ArvBinBusca.h"

Arv *cria(void)
{
  return NULL;
}

//imprime na ordem crescente
void imprime(Arv *a)
{
  if (a != NULL)
  {
    imprime(a->esq);
    printf("%d\t", a->info);
    imprime(a->dir);
  }
}

Arv *insere(Arv *a, int v)
{
  if (a == NULL)
  {
    a = (Arv *)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq, v);
  else /* v >= a->info */
    a->dir = insere(a->dir, v);
  return a;
}

Arv *retira(Arv *r, int v)
{
  if (r == NULL)
    return NULL;
  else if (r->info > v)
    r->esq = retira(r->esq, v);
  else if (r->info < v)
    r->dir = retira(r->dir, v);
  else
  { /* achou o nó a remover */
    /* nó sem filhos */
    if (r->esq == NULL && r->dir == NULL)
    {
      free(r);
      r = NULL;
    }
    /* nó só tem filho à direita */
    else if (r->esq == NULL)
    {
      Arv *t = r;
      r = r->dir;
      free(t);
    }

    /* só tem filho à esquerda */
    else if (r->dir == NULL)
    {
      Arv *t = r;
      r = r->esq;
      free(t);
    }
    /* nó tem os dois filhos */
    else
    {
      Arv *f = r->esq;
      while (f->dir != NULL)
      {
        f = f->dir;
      }
      r->info = f->info; /* troca as informações */
      f->info = v;
      r->esq = retira(r->esq, v);
    }
  }
  return r;
}
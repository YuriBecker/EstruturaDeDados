#include "arvore.h"

Arv *criaVazia()
{
  return NULL;
}

Arv *cria(char info, Arv *e, Arv *d)
{
  Arv *novaArv = (Arv *)malloc(sizeof(Arv));
  novaArv->info = info;
  novaArv->esq = e;
  novaArv->dir = d;
  return novaArv;
}

Arv *libera(Arv *a)
{
  if (!vazia(a))
  {
    libera(a->esq);
    libera(a->dir);
    free(a);
  }
  return NULL;
}

bool vazia(Arv *a)
{
  return a == NULL;
}

bool pertence(Arv *a, char info)
{
  if (vazia(a))
    return false;
  return a->info == info ||
         pertence(a->esq, info) ||
         pertence(a->dir, info);
}

void imprime(Arv *a)
{
  if (!vazia(a))
  {
    printf("%c ", a->info);
    imprime(a->esq);
    imprime(a->esq);
  }
}
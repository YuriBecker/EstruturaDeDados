#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
  int info;
  struct arv *esq;
  struct arv *dir;
} Arv;

Arv *cria(void);
void imprime(Arv *a);
Arv *insere(Arv *a, int v);
Arv *retira(Arv *r, int v);
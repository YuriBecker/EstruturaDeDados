#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arv
{
  char info;
  struct arv *esq;
  struct arv *dir;
} Arv;

Arv *criaVazia();
Arv *cria(char info, Arv *e, Arv *d);
Arv *libera(Arv *a);
bool vazia(Arv *a);
bool pertence(Arv *a, char info);
void imprime(Arv *a);
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
  int info;
  struct lista *prox;
} Lista;

Lista *createL(void);
Lista *insertL(Lista *lista, int num);
void showL(Lista *lista);
bool isEmptyL(Lista *lista);
Lista *searchL(Lista *lista, int value);
Lista *removeL(Lista *lista, int value);
Lista *freeL(Lista *lista);
Lista *insertOrderlyL(Lista *lista, int value);
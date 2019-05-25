#include <stdlib.h>
#include <stdio.h>

typedef struct listadupla
{
  int info;
  struct listadupla *ant;
  struct listadupla *prox;
} ListaD;

ListaD *insertL2(ListaD *l, int v);
ListaD *createL2(void);
void showL2(ListaD *l);
ListaD *searchL2(ListaD *l, int value);
ListaD *removeL2(ListaD *l, int v);
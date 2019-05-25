#include <stdio.h>
#include <stdlib.h>
#include "pilhaComVetor.h"

Pilha *pilha_cria(void)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->n = 0; /* inicializa com zero elementos */
  return p;
}

void pilha_push(Pilha *p, float v)
{
  printf("\n\nTentando inserir o valor %.2f na pilha que jah possui %d elementos (aceita no maximo % d elementos)\n ", v, p->n, N);
  if (p->n == N)
  {
    printf("\n\n*** Capacidade da pilha estourou! Vc nao pode inserir mais do que %d elementos\n\n",
           N);
    system("pause");
    exit(1);
  }
  printf("\n\tValor %.2f foi inserido na posicao %d\n", v, p->n);
  p->vet[p->n] = v;
  p->n++;
}

int pilha_vazia(Pilha *p)
{
  return (p->n == 0);
}

float pilha_pop(Pilha *p)
{
  float v;
  if (pilha_vazia(p))
  {
    printf("*** Pilha vazia!!\n");
    system("pause");
    exit(1);
  }
  /* retira elemento do topo */
  v = p->vet[p->n - 1];
  p->n--;
  return v;
}

void pilha_libera(Pilha *p)
{
  free(p);
}
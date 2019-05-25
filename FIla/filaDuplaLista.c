#include "filaDuplaLista.h"
#include <stdlib.h>
#include <stdio.h>

Fila2 *fila2_cria(void)
{
  Fila2 *f = (Fila2 *)malloc(sizeof(Fila2));
  f->ini = f->fim = NULL;
  return f;
}

void fila2_libera(Fila2 *f)
{
  Lista2 *q = f->ini;
  while (q != NULL)
  {
    printf("\nLiberando o no %.2f\n", q->info);
    Lista2 *t = q->prox;
    free(q);
    q = t;
  }
  printf("\nLiberando a fila\n");
  free(f);
}

void fila2_imprime(Fila2 *f) //IGUAL
{
  Lista2 *q;
  printf("\n\tIMPRIMINDO FILA:\n\t");
  for (q = f->ini; q != NULL; q = q->prox)
    printf("\t%.2f", q->info);
}

/* função auxiliar: insere no início */
Lista2 *ins2_ini(Lista2 *ini, float v)
{
  Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
  p->info = v;
  p->prox = ini;
  p->ant = NULL;
  if (ini != NULL) /* verifica se lista não estava vazia */
    ini->ant = p;
  return p;
}

/* função auxiliar: insere no fim */
Lista2 *ins2_fim(Lista2 *fim, float v)
{
  Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
  p->info = v;
  p->prox = NULL;
  p->ant = fim;
  if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
  return p;
}

/* função auxiliar: retira do início */
Lista2 *ret2_ini(Lista2 *ini)
{
  Lista2 *p = ini->prox;
  if (p != NULL) /* verifica se lista não ficou vazia */
    p->ant = NULL;
  free(ini);
  return p;
}

/* função auxiliar: retira do fim */
Lista2 *ret2_fim(Lista2 *fim)
{
  Lista2 *p = fim->ant;
  if (p != NULL) /* verifica se lista não ficou vazia */
    p->prox = NULL;
  free(fim);
  return p;
}

void fila2_insere_ini(Fila2 *f, float v)
{
  printf("\nTentando INSERIR NO INICIO o elemento %.2f", v);
  f->ini = ins2_ini(f->ini, v);
  if (f->fim == NULL) /* fila antes vazia? */
    f->fim = f->ini;
  fila2_imprime(f);
}

Lista2 *ins2_fim(Lista2 *fim, float v)
{
  Lista2 *p = (Lista2 *)malloc(sizeof(Lista2));
  p->info = v;
  p->prox = NULL;
  p->ant = fim;
  if (fim != NULL) /* verifica se lista não estava vazia */
    fim->prox = p;
  return p;
}

void fila2_insere_fim(Fila2 *f, float v)
{
  f->fim = ins2_fim(f->fim, v);
  if (f->ini == NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

Lista2 *ret2_ini(Lista2 *ini)
{
  Lista2 *p = ini->prox;
  if (p != NULL) /* verifica se lista não ficou vazia */
    p->ant = NULL;
  free(ini);
  return p;
}

float fila2_retira_ini(Fila2 *f)
{
  float v;
  if (fila2_vazia(f))
  {
    printf("Fila vazia.\n");
    exit(1); /* aborta programa */
  }
  v = f->ini->info;
  f->ini = ret2_ini(f->ini);
  if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
  return v;
}

Lista2 *ret2_fim(Lista2 *fim)
{
  Lista2 *p = fim->ant;
  if (p != NULL) /* verifica se lista não ficou vazia */
    p->prox = NULL;
  free(fim);
  return p;
}

float fila2_retira_fim(Fila2 *f)
{
  float v;
  if (vazia(f))
  {
    printf("Fila vazia.\n");
    exit(1); /* aborta programa */
  }
  v = f->fim->info;
  f->fim = ret2_fim(f->fim);
  if (f->fim == NULL) /* fila ficou vazia? */
    f->ini = NULL;
  return v;
}
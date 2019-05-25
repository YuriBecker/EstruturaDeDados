#include <stdio.h>
#include <stdlib.h>
#include "listahet.h"
/* Cria um nó com um retângulo */
ListaHet *cria_ret(ListaHet *l, float b, float h)
{
  Retangulo *r;
  ListaHet *p;
  /* aloca retângulo */
  r = (Retangulo *)malloc(sizeof(Retangulo));
  r->b = b;
  r->h = h;
  /* aloca nó */
  p = (ListaHet *)malloc(sizeof(ListaHet));
  p->tipo = RET;
  p->info = r;
  p->prox = l;
  return p;
}

/* Cria um nó com um triangulo */
ListaHet *cria_tri(ListaHet *l, float b, float h)
{
  Triangulo *t;
  ListaHet *p;
  /* aloca triangulo */
  t = (Triangulo *)malloc(sizeof(Triangulo));
  t->b = b;
  t->h = h;
  /* aloca nó */
  p = (ListaHet *)malloc(sizeof(ListaHet));
  p->tipo = TRI;
  p->info = t;
  p->prox = l;
  return p;
}

/* Cria um nó com um circulo */
ListaHet *cria_cir(ListaHet *l, float r)
{
  Circulo *c;
  ListaHet *p;
  /* aloca circulo */
  c = (Circulo *)malloc(sizeof(Circulo));
  c->r = r;
  /* aloca nó */
  p = (ListaHet *)malloc(sizeof(ListaHet));
  p->tipo = CIR;
  p->info = c;
  p->prox = l;
  return p;
}

void lst_imprime(ListaHet *l)
{
  ListaHet *p;
  float area;
  for (p = l; p != NULL; p = p->prox)
  {
    printf("\n\t\tTipo eh %d \n", p->tipo);
    if (p->tipo == RET)
    {
      Retangulo *r = (Retangulo *)p->info;
      area = r->b * r->h;
      printf("\n\t\t\tarea do retangulo eh base x altura = %.2f\n", area);
    }
    if (p->tipo == TRI)
    {
      Triangulo *r = (Triangulo *)p->info;
      area = (r->b * r->h) / 2;
      printf("\n\t\t\tarea do triangulo eh (base x altura)/2 = %.2f\n",
             area);
    }
    if (p->tipo == CIR)
    {
      Circulo *c = (Circulo *)p->info;
      area = 3.1415 * c->r * c->r;
      printf("\n\t\t\tarea do circulo eh pi * raio * raio = %.2f\n", area);
    }
  }
}
#include <stdlib.h>
#include "filaDupla.h"
#include <stdio.h>

Fila2 *fila2_cria(void)
{
  Fila2 *f = (Fila2 *)malloc(sizeof(Fila2));
  f->n = 0;
  f->ini = 0;
  return f;
}

void fila2_libera(Fila2 *f)
{
  free(f);
}

int fila2_vazia(Fila2 *f)
{
  return (f->n == 0);
}

void imprime_fila2(Fila2 *f) //IGUAL
{
  int fim;
  printf("\tIMPRIMINDO....");
  if (!fila2_vazia(f))
  {
    int fimNovo = (f->ini + f->n) % N; //calcula onde estah o fimNovo
    if (fimNovo == 0)
      fim = N - 1;
    else
      fim = fimNovo - 1;
    printf("\tPara imprimir, serao considerados inicio=%d e fim=%d\n", f->ini, fim);
    if (fim >= f->ini) //fim > inicio
      for (int i = f->ini; i <= fim; i++)
        printf("\t[%d]: %.2f", i, f->vet[i]);
    else //fim < inicio
    {
      for (int i = f->ini; i < N; i++) //imprime do inicio da fila ateh o fim do vetor (N-1)
        printf("\t[%d]: %.2f", i, f->vet[i]);
      for (int i = 0; i <= fim; i++) //imprime do inicio do vetor (0) teh o fim da fila
        printf("\t[%d]: %.2f", i, f->vet[i]);
    }
  } //fila vazia
  else
    printf("\tFila vazia\n");
}

void fila2_insere_ini(Fila2 *f, float v)
{
  int prec;
  printf("\n\nTentando INSERIR NO INICIO elemento %.2f", v);
  if (f->n == N)
  {
    printf("\n\tCapacidade da fila estourou.\n");
    system("pause");
    exit(1);
  }
  /* insere elemento na posição precedente ao início */
  prec = (f->ini - 1 + N) % N; /* decremento circular */
  printf("\n\tPrec eh %d, calculado como (f->ini[%d] - 1 + N) %% N", prec, f->ini);
  f->vet[prec] = v;
  f->ini = prec;
  f->n++;
  printf("\n\tElemento %.2f foi inserido NO INICIO - na posicao %d. \n\tFila possui agora %d elementos\n", v, prec, f->n);
  imprime_fila2(f);
}

void fila2_insere_fim(Fila2 *f, float v)
{
  int fim;
  printf("\n\nTentando INSERIR NO FIM elemento %.2f", v);
  if (f->n == N)
  {
    printf("\n\t*** Capacidade da fila estourou.\n");
    system("pause");
    exit(1);
  }
  /* insere elemento na próxima posição livre */
  fim = (f->ini + f->n) % N;
  printf("\n\tFim eh %d, calculado como (f->ini[%d] + f->n[%d]) %% N", fim, f->ini, f->n);
  f->vet[fim] = v;
  f->n++;
  printf("\n\tElemento %.2f foi inserido NO FIM - na posicao %d. \n\tFila possui agora %d elementos\n", v, fim, f->n);
  imprime_fila2(f);
}

float fila2_retira_fim(Fila2 *f)
{
  float v;
  printf("\n\nTentando REMOVER DO FIM");
  if (fila2_vazia(f))
  {
    printf("\nFila vazia.\n");
    system("pause");
    exit(1);
  }
  /* retira elemento do fim */
  int ult;
  ult = (f->ini + f->n - 1) % N;
  v = f->vet[ult];
  printf("\n\tElemento %.2f foi retirado DO FIM - da posicao %d.", v, ult);
  f->n--;
  printf("\n\tFila possui agora %d elementos\n", f->n);
  imprime_fila2(f);
  return v;
}

float fila2_retira_ini(Fila2 *f)
{
  float v;
  if (fila2_vazia(f))
  {
    printf("\n\t*** Fila vazia. Nao serah possivel remover o inicio\n");
    system("pause");
    exit(1);
  }
  /* retira elemento do início */
  v = f->vet[f->ini];
  f->ini = (f->ini + 1) % N;
  f->n--;
  return v;
}
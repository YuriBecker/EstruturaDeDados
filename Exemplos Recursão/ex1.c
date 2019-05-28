#include <stdio.h>
#include <stdlib.h>

void imprimir(int min, int max)
{
  printf("\t%d", min);
  if (min < max)
    imprimir(min + 1, max);
}

int main()
{
  int min, max;
  printf("\nInforme o intervalo inicial: ");
  scanf("%d", &min);
  printf("\nInforme o intervalo final: ");
  scanf("%d", &max);
  imprimir(min, max);
}
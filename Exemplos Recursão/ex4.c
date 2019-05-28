#include <stdio.h>
#include <stdlib.h>
int sucessor(int a)
{
  return a + 1;
}
int predecessor(int a)
{
  return a - 1;
}
int calculaSoma(int x, int y)
{
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  return calculaSoma(sucessor(x), predecessor(y));
}
int main()
{
  int x, y, resultado;
  printf("\nInforme o valor de x: ");
  scanf("%d", &x);
  printf("\nInforme o valor de y: ");
  scanf("%d", &y);
  resultado = calculaSoma(x, y);
  printf("\nO resultado eh %d\n", resultado);
  system("pause");
}
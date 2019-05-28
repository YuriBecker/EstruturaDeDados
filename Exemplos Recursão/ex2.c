#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float potencia(int x, int n)
{
  if (n > 0)
    return x * potencia(x, n - 1);
  return 1;
}
int main()
{
  int x, n;
  printf("\nInforme a base x: ");
  scanf("%d", &x);
  printf("\nInforme o expoente n: ");
  scanf("%d", &n);
  float result;
  result = potencia(x, abs(n));
  if (n < 0) //expoente negativo
    result = 1.0 / result;
  printf("\nO resultado eh %.4f\n", result);
  system("pause");
}
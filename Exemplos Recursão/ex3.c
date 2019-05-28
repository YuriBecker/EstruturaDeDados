#include <stdio.h>
#include <stdlib.h>
float calculaS(int n, int d)
{
  float s = (float)n / d;
  if (n < 99)
    s = s + calculaS(n + 2, d + 1);
  return s;
}
int main()
{
  float S = 0;
  S = calculaS(1, 1);
  printf("\nO resultado eh %.2f\n", S);
  system("pause");
}
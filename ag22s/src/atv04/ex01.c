#include <stdio.h>

int multiplica(int a, int b)
{
  return a * b;
}

int quadrado(int a)
{
  return a * a;
}

int cubo(int a)
{
  return a * a * a;
}

int pol_cubo(int a, int b, int c, int d, int x)
{
  //ax³ + bx² + cx + d
  return a * cubo(x) + b * quadrado(x) + c * x + d;
}

int main(void)
{
  int i, n;
  int a, b, c, d, x;

  scanf("%i", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%i %i %i %i %i", &a, &b, &c, &d, &x);
    printf("%i %i %i %i\n", cubo(x), quadrado(x), multiplica(c, x), pol_cubo(a, b, c, d, x));
  }
}
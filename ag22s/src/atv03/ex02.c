#include <stdio.h>

int main(void)
{
  int i, j, cont, n = 0;

  scanf("%d", &n);

  double m[n][n];

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%lf", &m[i][j]);
    }
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      double soma = 0;
      for (cont = 0; cont < n; cont++)
      {
        double mult = m[i][cont] * m[cont][j];
        soma += mult;
      }
      printf("%.1lf ", soma);
    }
    printf("\n");
  }

  return 0;
}
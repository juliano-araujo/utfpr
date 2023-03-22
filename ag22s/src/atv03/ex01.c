#include <stdio.h>

int main(void)
{
  int i, j, n = 0;

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
      printf("%.1lf ", m[i][j] * 2);
    }
    printf("\n");
  }

  return 0;
}
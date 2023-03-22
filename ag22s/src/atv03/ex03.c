#include <stdio.h>

int main(void)
{
  int i, j, m[3][3];

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      scanf("%d", &m[i][j]);
    }
  }

  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      printf("%d ", m[j][i]);
    }
    printf("\n");
  }

  return 0;
}
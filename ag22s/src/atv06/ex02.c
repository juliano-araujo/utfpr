#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz(int m, int n)
{
  int i, **mat;

  mat = (int **)malloc(m * sizeof(int *));

  if (mat == NULL)
    return NULL;

  for (i = 0; i < n; i++)
  {
    mat[i] = (int *)malloc(n * sizeof(int));
    if (mat[i] == NULL)
    {
      while (i)
      {
        i--;
        free(mat[i]);
      }
      free(mat);

      return NULL;
    }
  }

  return mat;
}

int main()
{
  int **p;
  int m, n, i, j;
  scanf("%d %d", &m, &n);
  p = aloca_matriz(m, n);

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      p[i][j] = (i * m) + (j + 1);
    }
  }
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
}
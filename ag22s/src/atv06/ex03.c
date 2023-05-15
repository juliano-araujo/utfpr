#include <stdio.h>
#include <stdlib.h>

int **aloca_matriz_quadrada(int n)
{
  int i, **mat;

  mat = (int **)malloc(n * sizeof(int *));

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
  int n, i, j, **p;
  scanf("%d", &n);
  p = aloca_matriz_quadrada(n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      p[i][j] = (i * n) + (j + 1);
    }
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }
}
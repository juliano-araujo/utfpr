#include <stdio.h>

int main()
{
  int n, i, j;

  scanf("%d", &n);

  int vet[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &vet[i]);
  }

  for (i = 0; i < n; i++)
  {
    int is_unique = 1;
    for (j = 0; j < n; j++)
    {
      if (j == i)
        continue;

      if (vet[i] == vet[j])
      {
        is_unique = 0;
        break;
      }
    }

    if (is_unique)
    {
      printf("%d\n", vet[i]);
    }
  }
}
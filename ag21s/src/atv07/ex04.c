#include <stdio.h>

int main()
{
  int i, n, before1 = 1, before2 = 1;

  scanf("%d", &n);

  for (i = 1; i <= n; i++)
  {
    if (i == 1 || i == 2)
    {
      printf("%d\n", 1);
      continue;
    }

    int valor = before1 + before2;
    before1 = before2;
    before2 = valor;

    printf("%d\n", valor);
  }
}
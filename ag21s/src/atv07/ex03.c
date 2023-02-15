#include <stdio.h>

int main()
{
  int a, b, first, last, i, soma = 0;

  scanf("%d", &a);
  scanf("%d", &b);

  if (a > b)
  {
    first = b;
    last = a;
  }
  else
  {
    first = a;
    last = b;
  }

  for (i = first; i <= last; i++)
  {
    printf("%d ", i);

    soma += i;
  }

  printf("\nSoma = %d", soma);
}
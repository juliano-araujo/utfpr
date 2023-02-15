#include <stdio.h>

int main()
{
  int i, max = 0, pos, n;

  for (i = 1; i <= 10; i++)
  {
    scanf("%d", &n);

    if (n > max)
    {
      max = n;
      pos = i;
    }
  }

  printf("%d\n%d", max, pos);
}
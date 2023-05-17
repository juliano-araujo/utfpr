#include <stdio.h>

int somatorio(int n)
{
  if (n == 1)
  {
    return 1;
  }

  return n + somatorio(n - 1);
}

int main(void)
{
  int n, num;
  scanf("%d", &n);
  num = somatorio(n);
  printf("%d", num);
}

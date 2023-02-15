#include <stdio.h>

int main()
{
  int i;
  while (1)
  {
    int num = 0;
    scanf("%d", &num);

    if (num == 0)
    {
      break;
    }

    for (i = 1; i <= num; i++)
    {
      if (num % i == 0)
      {
        printf("%d ", i);
      }
    }
    printf("\n");
  };
}
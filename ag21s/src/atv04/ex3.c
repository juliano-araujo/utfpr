#include <stdio.h>

int main()
{
  int num = 0, maxNum = 0;

  do
  {
    scanf("%d", &num);

    if (num >= -100 && num <= 100)
    {
      if (num > maxNum)
      {
        maxNum = num;
      }
    }
    else if (num != 0)
    {
      printf("Valor invalido! Tente novamente!\n");
    }

  } while (num != 0);

  printf("%d", maxNum);
}

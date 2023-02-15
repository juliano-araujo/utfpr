#include <stdio.h>

int main()
{
  int num = 0;

  do
  {
    scanf("%d", &num);

    if (num > 2 && num < 1000)
    {
      int i = 1;

      do
      {
        int prod = i * num;

        printf("%d X %d = %d\n", i, num, prod);

        i++;
      } while (i <= 10);

      break;
    }

    printf("Valor invalido! Tente novamente!\n");
  } while (num <= 2 || num >= 1000);
}

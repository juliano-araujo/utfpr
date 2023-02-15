#include <stdio.h>

int main()
{
  int num = 0;

  do
  {
    scanf("%d", &num);

    if (num >= 2 && num <= 100)
    {
      int i = 2, isPrimo = 1;

      while (i < num)
      {
        if (num % i == 0)
        {
          isPrimo = 0;

          break;
        }

        i++;
      }

      if (isPrimo)
      {
        printf("Primo\n");
      }
      else
      {
        printf("Nao primo\n");
      }
    }
    else if (num != 0)
    {
      printf("Valor invalido! Tente novamente!\n");
    }

  } while (num != 0);
}

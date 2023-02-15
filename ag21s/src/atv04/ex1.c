#include <stdio.h>

int main()
{
  int num = 0;

  do
  {
    scanf("%d", &num);

    if (num >= -100 && num <= 100)
    {
      if (num == 0)
      {
        printf("NULL");
      }
      else
      {
        if (num % 2 == 0)
        {
          printf("EVEN ");
        }
        else
        {
          printf("ODD ");
        }

        if (num > 0)
        {
          printf("POSITIVE");
        }
        else
        {
          printf("NEGATIVE");
        }
      }
    }
    else if (num != -101)
    {
      printf("Valor invalido! Tente novamente!");
    }

    printf("\n");
  } while (num != -101);
}

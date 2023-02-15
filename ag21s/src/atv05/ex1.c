#include <stdio.h>

int main()
{
  int num = 0;

  do
  {
    scanf("%d", &num);

    if (num > 5 && num < 200)
    {
      int i = 2;

      do
      {
        int quad = i * i;

        printf("%d^2 = %d\n", i, quad);

        i = i + 2;
      } while (i <= num);

      break;
    }

    printf("Valor invalido! Tente novamente!\n");
  } while (num <= 5 || num >= 200);
}

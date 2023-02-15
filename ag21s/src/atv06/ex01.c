#include <stdio.h>

int main()
{
  int num, i = 0, soma = 0, min = -1, max = 0;

  while (1)
  {
    scanf("%d", &num);

    if (num == 0)
    {
      break;
    }

    if (num < 1)
    {
      printf("Valor invalido! Tente novamente!\n");
      continue;
    }

    if (min == -1)
    {
      min = num;
    }

    if (num < min)
    {
      min = num;
    }

    if (num > max)
    {
      max = num;
    }

    soma += num;
    i++;
  };

  float media = soma / (float)i;

  printf("Maior = %d\n", max);
  printf("Menor = %d\n", min);
  printf("Media = %.2f\n", media);
}
#include <stdio.h>

int main()
{
  int i, valor;

  for (i = 0; i < 10; i++)
  {
    scanf("%d", &valor);

    if (valor > 100 || valor < 0)
    {
      printf("Fora de intervalo: x = %d\n", valor);
      continue;
    }

    int intervalo = 0;

    if (valor != 0)
    {
      intervalo = (valor - 1) / 25;
    }

    char simbolo = intervalo != 0 ? '(' : '[';

    int primeiroNum = intervalo * 25;
    int segundoNum = (intervalo + 1) * 25;

    printf("Intervalo %c%d,%d]: x = %d\n", simbolo, primeiroNum, segundoNum, valor);
  }
}
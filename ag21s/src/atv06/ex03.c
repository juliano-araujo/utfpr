#include <stdio.h>

int main()
{
  float valor_ingresso, soma = 0;

  scanf("%f", &valor_ingresso);

  while (1)
  {
    int dia, perc_desconto = 0;
    char categoria = ' ';

    scanf("%d", &dia);

    if (dia == -1)
    {
      break;
    }

    scanf(" %c", &categoria);

    if (dia >= 6 && dia <= 13)
    {
      if (categoria == 'E')
      {
        perc_desconto = 15;
      }
      else if (categoria == 'A')
      {
        perc_desconto = 10;
      }
    }
    else if (dia >= 14 && dia <= 24)
    {
      if (categoria == 'E')
      {
        perc_desconto = 10;
      }
      else if (categoria == 'A')
      {
        perc_desconto = 5;
      }
    }

    float valor_desconto = valor_ingresso * (perc_desconto / 100.00);
    float valor = valor_ingresso - valor_desconto;

    soma += valor;
  }

  printf("%.2f", soma);
}
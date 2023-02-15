#include <stdio.h>

int main()
{
  float divida;
  int i, tipoPessoa;

  scanf("%f", &divida);
  scanf("%d", &tipoPessoa);

  for (i = 0; i < 5; i++)
  {
    int parcelas, juros;
    float valorParcelas;

    if (i == 0)
    {
      parcelas = 1;
      juros = 0;
    }
    else
    {
      parcelas = i * 3;
      juros = 10;

      if (tipoPessoa == 0)
      {
        juros += (i - 1) * 10;
      }
      else if (tipoPessoa == 1)
      {
        juros += (i - 1) * 5;
      }
    }

    float valorJuros = divida * (juros / (float)100);
    float valorDivida = divida + valorJuros;
    float valorParcela = valorDivida / parcelas;

    printf("Valor Divida: %.2f   Valor Juros: %.2f   Parcelas: %d   Valor Parcela: %.2f\n", valorDivida, valorJuros, parcelas, valorParcela);
  }
}

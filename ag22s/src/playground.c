#include <stdio.h>
int main()
{
  float dividainicial, divida;
  int pessoa, parcelas = 1;
  float juros = 0, valorparcelas;

  scanf("%f %d", &dividainicial, &pessoa);

  printf("Valor divida: %.2f   ", dividainicial);
  printf("Juros: %.2f   ", juros);
  printf("Parcelas: 1   ");
  printf("Valor parcela: %.2f\n", dividainicial);

  juros = 0.1f;
  parcelas = 3;
  valorparcelas = 0;

  if (pessoa == 0)
  {
    while (juros <= 0.4f)
    {
      divida = dividainicial + (juros * dividainicial);
      valorparcelas = divida / parcelas;

      printf("Valor divida: %.2f   ", divida);
      printf("Juros: %.2f   ", juros * 1000);
      printf("Parcela: %d   ", parcelas);
      printf("Valor parcela: %.2f\n", valorparcelas);

      parcelas += 3;
      juros += 0.10f;
    }
  }

  if (pessoa == 1)
  {
    while (juros <= 0.25f)
    {
      divida = dividainicial + (juros * dividainicial);
      valorparcelas = divida / parcelas;

      printf("Valor divida: %.2f   ", divida);
      printf("Juros: %.2f   ", juros * 1000);
      printf("Parcela: %d   ", parcelas);
      printf("Valor parcela: %.2f\n", valorparcelas);

      parcelas += 3;
      juros += 0.05f;
    }
  }
}
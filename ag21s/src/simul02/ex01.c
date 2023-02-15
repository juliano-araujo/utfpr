#include <stdio.h>

int main()
{
  int num_lanc, i;
  float pagar = 0, receber = 0, saldo;

  scanf("%d", &num_lanc);

  for (i = 0; i < num_lanc; i++)
  {
    float valor;

    scanf("%f", &valor);

    if (valor > 0)
    {
      receber += valor;
    }
    else
    {
      pagar += valor;
    }
  }

  saldo = receber + pagar;

  printf("Pagar: R$ %.2f\n", pagar);
  printf("Receber: R$ %.2f\n", receber);
  printf("Saldo: R$ %.2f\n", saldo);
}
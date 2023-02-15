#include <stdio.h>
int main()
{
  float produto, reajuste;

  scanf("%f", &produto);
  scanf("%f", &reajuste);

  float valorReajuste = produto * (reajuste / 100);
  float produtoReajustado = produto + valorReajuste;

  printf("Valor do reajuste: %.2f\nValor do produto reajustado: %.2f", valorReajuste, produtoReajustado);
}
#include <stdio.h>
int main()
{
  int consumo;
  double tarifa, taxas_impostos, servicos;

  scanf("%d", &consumo);
  scanf("%lf", &tarifa);
  scanf("%lf", &taxas_impostos);
  scanf("%lf", &servicos);

  double valor_consumo = consumo * tarifa;
  double valor_total = valor_consumo + taxas_impostos + servicos;

  printf("Dados do faturamento:\n");
  printf("Consumo............:%d kWh\n", consumo);
  printf("Tarifa (R$)........:%.3f\n", tarifa);
  printf("Total (R$).........:%.2f\n", valor_consumo);
  printf("Taxas e impostos...:%.2f\n", taxas_impostos);
  printf("Servicos...........:%.2f\n", servicos);
  printf("VALOR (R$).........:%.2f", valor_total);
}
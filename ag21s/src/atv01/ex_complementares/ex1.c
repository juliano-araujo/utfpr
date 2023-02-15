#include <stdio.h>
int main()
{
  int ano_vendas, ano_ref, perc_vendas;

  scanf("%d", &ano_vendas);
  scanf("%d", &ano_ref);
  scanf("%d", &perc_vendas);

  printf("Tivemos no ano %d um aumento de %d pontos percentuais nas vendas em relação ao ano %d.\nTivemos no ano %d um aumento de %d%% nas vendas em relação ao ano %d.", ano_vendas, perc_vendas, ano_ref, ano_vendas, perc_vendas, ano_ref);
}
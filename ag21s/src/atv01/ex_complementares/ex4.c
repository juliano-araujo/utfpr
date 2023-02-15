#include <stdio.h>
int main()
{
  int qtdPassageiros;
  float pesoBag, distancia;

  scanf("%d", &qtdPassageiros);
  scanf("%f", &pesoBag);
  scanf("%f", &distancia);

  float consumoCombustivel = ((qtdPassageiros * 0.03) + (pesoBag * 0.89)) * (0.017 * distancia);

  printf("O consumo estimado de combustível é de %.2f litros de querosene", consumoCombustivel);
}
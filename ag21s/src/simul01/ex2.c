#include <stdio.h>

int main()
{
  float salario, reajuste;

  scanf("%f", &salario);
  scanf("%f", &reajuste);

  float novo_salario = salario + (salario * (reajuste / 100));

  printf("R$ %.2f", novo_salario);
}
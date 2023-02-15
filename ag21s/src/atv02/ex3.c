#include <stdio.h>

int main()
{
  int item, quantidade;

  scanf("%d", &item);
  scanf("%d", &quantidade);

  float valor_item;

  switch (item)
  {
  case 1:
    valor_item = 4;
    break;
  case 2:
    valor_item = 4.5;
    break;
  case 3:
    valor_item = 5;
    break;
  case 4:
    valor_item = 2;
    break;
  case 5:
    valor_item = 1.5;
    break;
  default:
    printf("Codigo invalido");
    return 0;
    break;
  }

  float valor_total = valor_item * quantidade;

  printf("Total: R$ %.2f", valor_total);
}
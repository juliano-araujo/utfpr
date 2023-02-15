#include <stdio.h>

int main()
{
  int vinho, prato;

  printf("Selecione o tipo de vinho:\n1 - Vinho Tinto\n2 - Vinho Rose\n3 - Vinho Branco\n4 - Espumante\n");

  scanf("%d", &vinho);

  switch (vinho)
  {
  case 1:
    printf("Vinho selecionado: Tinto\n");

    printf("Selecione um dos seguintes pratos:\n1. Hamburguer de picanha\n2. Espaguete a bolonhesa\n3. Pizza 4 queijos\n");

    scanf("%d", &prato);

    switch (prato)
    {
    case 1:
      printf("Prato selecionado: Hamburguer de picanha");
      break;
    case 2:
      printf("Prato selecionado: Espaguete a bolonhesa");
      break;

    case 3:
      printf("Prato selecionado: Pizza 4 queijos");
      break;
    default:
      printf("Prato invalido!");
    }

    break;
  case 2:
    printf("Vinho selecionado: Rose\n");

    printf("Selecione um dos seguintes pratos:\n1. Lulas a dore\n2. Batatas fritas com mostarda dijon\n3. Pastel de carne\n");

    scanf("%d", &prato);

    switch (prato)
    {
    case 1:
      printf("Prato selecionado: Lulas a dore");
      break;
    case 2:
      printf("Prato selecionado: Batatas fritas com mostarda dijon");
      break;
    case 3:
      printf("Prato selecionado: Pastel de carne");
      break;
    default:
      printf("Prato invalido!");
    }

    break;
  case 3:
    printf("Vinho selecionado: Branco\n");

    printf("Selecione um dos seguintes pratos:\n1. Peixe assado no forno\n2. Verduras gratinadas\n3. Frango assado\n");

    scanf("%d", &prato);

    switch (prato)
    {
    case 1:
      printf("Prato selecionado: Peixe assado no forno");
      break;
    case 2:
      printf("Prato selecionado: Verduras gratinadas");
      break;
    case 3:
      printf("Prato selecionado: Frango assado");
      break;
    default:
      printf("Prato invalido!");
    }

    break;
  case 4:
    printf("Vinho selecionado: Espumante\n");

    printf("Selecione um dos seguintes pratos:\n1. Frutos do mar grelhados\n2. Feijoada\n3. Espaguete ao molho sugo\n");

    scanf("%d", &prato);

    switch (prato)
    {
    case 1:
      printf("Prato selecionado: Frutos do mar grelhados");
      break;
    case 2:
      printf("Prato selecionado: Feijoada");
      break;
    case 3:
      printf("Prato selecionado: Espaguete ao molho sugo");
      break;
    default:
      printf("Prato invalido!");
    }

    break;
  default:
    printf("Vinho invalido!");
  }
}
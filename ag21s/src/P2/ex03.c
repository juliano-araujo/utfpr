#include <stdio.h>

int main()
{
  int astra = 0, coron = 0, janss = 0, pfize = 0;

  while (1)
  {
    char vacina;

    scanf(" %c", &vacina);

    if (vacina == 'X')
    {
      break;
    }

    switch (vacina)
    {
    case 'A':
      astra++;
      break;
    case 'C':
      coron++;
      break;
    case 'J':
      janss++;
      break;
    case 'P':
      pfize++;
      break;
    default:
      printf("Tipo de vacina invalida! Tente novamente.\n");
    }
  }

  printf("Numero de doses aplicadas:\n");
  printf("Astrazeneca: %d\n", astra);
  printf("Coronavac: %d\n", coron);
  printf("Janssen: %d\n", janss);
  printf("Pfizer: %d", pfize);
}
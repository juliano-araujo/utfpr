#include <stdio.h>

int main()
{
  char orig, dest, c;
  float valorTotal;
  int cont = 0;

  scanf("%c", &orig);
  scanf(" %c", &dest);

  if (!((orig == 'A' || orig == 'B' || orig == 'C' || orig == 'D') && (dest == 'A' || dest == 'B' || dest == 'C' || dest == 'D')))
  {
    printf("Erro: origem ou destino inexistente!");

    return 1;
  }

  int temp = orig > dest ? -1 : 1;

  printf("Viagem: ");

  for (c = orig; c != dest; c = c + temp)
  {
    printf("%c ", c);
    cont++;
  }

  valorTotal = cont * 50;

  printf("%c\n", dest);
  printf("Valor Total: %.2f", valorTotal);
}

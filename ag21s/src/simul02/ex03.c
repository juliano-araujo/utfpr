#include <stdio.h>

int main()
{
  int cont_vogal = 0, cont_consoante = 0;
  char letra;

  do
  {
    scanf("%c", &letra);

    switch (letra)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      cont_vogal++;
      break;

    case '!':
      break;

    default:
      cont_consoante++;
    }

  } while (letra != '!');

  if (cont_consoante == cont_vogal)
  {
    printf("Empate!");
  }
  else if (cont_consoante > cont_vogal)
  {
    printf("Ha mais consoantes que vogais.");
  }
  else
  {
    printf("Ha mais vogais que consoantes.");
  }
}
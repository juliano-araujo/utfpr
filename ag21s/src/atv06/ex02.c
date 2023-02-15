#include <stdio.h>

int main()
{
  int cont = 0, cont_a = 0, cont_e = 0, cont_i = 0, cont_o = 0, cont_u = 0;
  char letra;

  do
  {
    scanf("%c", &letra);

    switch (letra)
    {
    case 'a':
    case 'A':
      cont_a++;
      break;

    case 'e':
    case 'E':
      cont_e++;
      break;

    case 'i':
    case 'I':
      cont_i++;
      break;

    case 'o':
    case 'O':
      cont_o++;
      break;

    case 'u':
    case 'U':
      cont_u++;
      break;
    }
    cont++;

  } while (letra != 'x');

  printf("a: %d, e: %d, i: %d, o: %d, u: %d, total de letras: %d", cont_a, cont_e, cont_i, cont_o, cont_u, cont);
}
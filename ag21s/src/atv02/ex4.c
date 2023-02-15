#include <stdio.h>

int main()
{
  char nota;

  scanf("%c", &nota);

  switch (nota)
  {
  case 'a':
  case 'A':
    printf("Excelente! Parabens!");
    break;
  case 'b':
  case 'B':
  case 'c':
  case 'C':
    printf("Voce foi bem.");
    break;
  case 'd':
  case 'D':
    printf("Foi por muito pouco!");
    break;
  case 'f':
  case 'F':
    printf("Estudar mais na proxima.");
    break;
  default:
    printf("Valor invalido.");
  }
}
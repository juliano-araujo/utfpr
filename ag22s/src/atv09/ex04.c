#include <stdio.h>

void lerItensDaLista(FILE *arq)
{

  char str[50];

  while (fscanf(arq, "%s", str) != EOF)
  {
    printf("%s\n", str);
  }
}

int main(void)
{
  FILE *arq;
  arq = fopen("ListaCompras.txt", "w+");

  // 1o. item
  fprintf(arq, "%s\n", "Leite");
  // 2o. item
  fprintf(arq, "%s\n", "Pao");
  // 3o. item
  fprintf(arq, "%s\n", "Presunto");
  // 4o. item
  fprintf(arq, "%s\n", "Manteiga");

  rewind(arq);

  lerItensDaLista(arq);
  fclose(arq);
}
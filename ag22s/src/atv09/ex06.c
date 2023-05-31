#include <stdio.h>

void gravaNoArquivo(FILE *fp, int v[], int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    fprintf(fp, "%d ", v[i]);
  }

  rewind(fp);
}

int somaArquivo(FILE *fp)
{
  int soma = 0;

  int num;
  while (fscanf(fp, "%d", &num) != EOF)
  {
    soma += num;
  }

  return soma;
}

int main(void)
{
  int v[] = {1, 2, 3, 4, 5};
  FILE *fp = fopen("arquivo.txt", "w+");
  gravaNoArquivo(fp, v, 5);
  printf("Soma = %d\n", somaArquivo(fp));
  fclose(fp);
}
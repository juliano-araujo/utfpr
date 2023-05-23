#include <stdio.h>
#include <string.h>

void gravaNoArquivo(FILE *fp, char *v)
{
  const char QUEBRA_LINHA = '\n';
  int i;

  for (i = 0; i < strlen(v); i++)
  {
    fputc(v[i], fp);
    fputc(QUEBRA_LINHA, fp);
  }

  rewind(fp);
}

int encontrouCaractereArquivo(FILE *arq, char chBusca)
{
  char ch;
  while ((ch = fgetc(arq)) != EOF)
  {
    if (ch == chBusca)
      return 1;
  }
  return 0;
}

int main(void)
{
  char v[20] = "Algoritmo";
  FILE *fp = fopen("arquivo.txt", "w+");
  gravaNoArquivo(fp, v);
  char ch = 'a';
  int encontrou = encontrouCaractereArquivo(fp, ch);

  if (encontrou)
    printf("Caractere = %c encontrado no arquivo.\n", ch);
  else
    printf("Caractere = %c nao foi encontrado no arquivo.\n", ch);

  fclose(fp);
}
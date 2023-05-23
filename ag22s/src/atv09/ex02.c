#include <stdio.h>

int contaCaracteresArquivo(FILE *arq)
{
  int cont = 0;

  char ch;
  while ((ch = fgetc(arq)) != EOF)
  {
    if (ch != '\n' && ch != ' ')
    {
      cont++;
    }
  }

  return cont;
}

int main(void)
{

  FILE *fp = fopen("teste.txt", "w+");
  char *s = "oi oi oi";
  fputs(s, fp);
  rewind(fp);
  printf("%d\n", contaCaracteresArquivo(fp));
  fclose(fp);
}
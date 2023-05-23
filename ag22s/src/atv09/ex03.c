#include <stdio.h>
#include <stdlib.h>

char *findAlphabeticFile(FILE *f)
{
  int tam = 10, i = 0, tem = 0;
  char *v = (char *)calloc(tam, sizeof(char));

  char ch;
  while ((ch = fgetc(f)) != EOF)
  {
    if ((ch >= 65 && ch <= 89) || (ch >= 97 && ch <= 122))
    {
      if (i == tam)
      {
        tam *= 2;
        v = (char *)realloc(v, tam);
      }

      v[i++] = ch;
      tem = 1;
    }
  }

  if (tem == 0)
  {
    free(v);
    return NULL;
  }

  return v;
}

int main(void)
{
  FILE *f = fopen("arquivo.txt", "w+");
  char frase[] = "Teste 123 Teste 123";
  fprintf(f, "%s", frase);
  rewind(f);
  char *s = findAlphabeticFile(f);
  printf("%s\n", s);
  fclose(f);
  free(s);
}
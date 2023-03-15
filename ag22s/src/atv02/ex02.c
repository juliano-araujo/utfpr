#include <stdio.h>
#include <string.h>

int main(void)
{
  char frase[30];
  int i;

  scanf("%[^\n]s", frase);

  for (i = 0; i < strlen(frase); i++)
  {
    if (frase[i] == ' ')
      continue;
    else if (frase[i] == 'z')
      frase[i] = 'A';
    else
      frase[i] = frase[i] - 31;
  }

  printf("%s", frase);

  return 0;
}
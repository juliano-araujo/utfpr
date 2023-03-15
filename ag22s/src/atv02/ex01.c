#include <stdio.h>
#include <string.h>

int main(void)
{
  char frase[30];
  int i;

  scanf("%[^\n]s", frase);

  for (i = 0; i < strlen(frase); i++)
  {
    char c = frase[i];

    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
    {
      frase[i] = '_';
    }
  }

  printf("%s", frase);

  return 0;
}
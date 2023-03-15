#include <stdio.h>
#include <string.h>

int main(void)
{
  int tamanho, i;
  char textoS[51];
  char fraseFinal[51];

  scanf("%d", &tamanho);

  int vetorV[tamanho];

  for (i = 0; i < tamanho; i++)
  {
    scanf("%d", &vetorV[i]);
  }

  scanf(" %[^\n]s", textoS);

  for (i = 0; i < tamanho; i++)
  {
    fraseFinal[i] = textoS[vetorV[i]];
  }

  fraseFinal[i] = '\0';

  printf("%s", fraseFinal);

  return 0;
}
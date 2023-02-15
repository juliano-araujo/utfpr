#include <stdio.h>
int main()
{
  int eleitores, votosBrancos, votosNulos;

  scanf("%d", &eleitores);
  scanf("%d", &votosBrancos);
  scanf("%d", &votosNulos);

  int votosValidos = eleitores - (votosBrancos + votosNulos);
  float percentualValidos = ((float)votosValidos / eleitores) * 100;
  float percentualBrancos = ((float)votosBrancos / eleitores) * 100;
  float percentualNulos = ((float)votosNulos / eleitores) * 100;

  printf("Total de votos validos: %d\n", votosValidos);
  printf("----------------------------\n");
  printf("Votos validos: %.2f%%\n", percentualValidos);
  printf("Votos brancos: %.2f%%\n", percentualBrancos);
  printf("Votos nulos: %.2f%%", percentualNulos);
}
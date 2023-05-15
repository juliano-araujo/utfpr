#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int tamanho)
{
  int *vet = NULL;

  vet = (int *)calloc(tamanho, sizeof(int));

  return vet;
}

void le_elementos(int *vet, int tam)
{
  int i;

  for (i = 0; i < tam; i++)
  {
    scanf("%d", &vet[i]);
  }
}

void print_vetor(int *vet, int tam)
{
  int i, soma = 0;

  for (i = 0; i < tam; i++)
  {
    int item = vet[i];
    soma += item;

    printf("v[%d]=%d\n", i, item);
  }

  float media = (float)soma / tam;
  printf("Media=%.2f", media);
}

int main()
{
  int n, *p;
  scanf("%d", &n);
  p = aloca_vetor(n);
  le_elementos(p, n);
  print_vetor(p, n);

  return 0;
}
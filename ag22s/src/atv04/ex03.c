#include <stdio.h>

void printVetor(int *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("%d ", vetor[i]);
  }
}

void inverter(int *vetor, int tam)
{
  for (int i = 0; i < tam / 2; i++)
  {
    int aux = vetor[tam - i - 1];
    vetor[tam - i - 1] = vetor[i];
    vetor[i] = aux;
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  int vetor[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &vetor[i]);
  }
  inverter(vetor, n);
  printVetor(vetor, n);
}

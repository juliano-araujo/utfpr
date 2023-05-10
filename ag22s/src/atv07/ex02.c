#include <stdio.h>

typedef struct produtor_t
{
  int codProdutor;
  char grao;
  float quantidade;
} produtor;

void le_graos(produtor *prod)
{
  printf("Informe o codigo do produtor:\n");
  scanf("%d", &prod->codProdutor);

  printf("Informe o grao[F,M,S,T]:\n");
  scanf(" %c", &prod->grao);

  printf("Informe a quantidade de toneladas:\n");
  scanf("%f", &prod->quantidade);
}

void imprime_totais(produtor prod_arr[], int n)
{
  float feijao = 0;
  float milho = 0;
  float soja = 0;
  float trigo = 0;

  int i;

  for (i = 0; i < n; i++)
  {
    produtor prod = prod_arr[i];
    char grao = prod.grao;

    switch (grao)
    {
    case 'F':
      feijao += prod.quantidade;
      break;

    case 'M':
      milho += prod.quantidade;
      break;

    case 'S':
      soja += prod.quantidade;
      break;

    case 'T':
      trigo += prod.quantidade;
      break;
    }
  }

  printf("\nTotal de toneladas dos Produtos: \n");
  printf("Feijao: %.2f\n", feijao);
  printf("Milho: %.2f\n", milho);
  printf("Soja: %.2f\n", soja);
  printf("Trigo: %.2f", trigo);
}

int main(void)
{
  int n;
  printf("Informe o tamanho do vetor: ");
  scanf("%d", &n);
  printf("\n");
  // Declaração da variável tipo struct
  produtor entrada[n];

  for (int i = 0; i < n; i++)
  {
    le_graos(&entrada[i]);
  }
  imprime_totais(entrada, n);
}
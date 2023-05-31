#include <stdio.h>
#include <stdlib.h>

typedef struct Aposta
{
  int nroCartao;
  int dezenas[6];
} APOSTA;

int *lerDezenasDoCartao(FILE *arq, int cartao)
{
  APOSTA aposta;

  while (fread(&aposta, sizeof(aposta), 1, arq))
  {
    if (aposta.nroCartao == cartao)
    {
      int *vet = (int *)calloc(6, sizeof(int));

      int i;

      for (i = 0; i < 6; i++)
      {
        vet[i] = aposta.dezenas[i];
      }

      return vet;
    }
  }

  return NULL;
}

void mostrarDezenasDoCartao(int *v, int tam)
{
  if (v == NULL)
  {
    printf("Dezenas nao localizadas.");
    return;
  }

  int i;

  for (i = 0; i < tam; i++)
  {
    printf("%d ", v[i]);
  }
}

int main(void)
{
  FILE *arq;
  arq = fopen("Apostas.bin", "a+b");

  APOSTA aposta;
  aposta.nroCartao = 1548;
  aposta.dezenas[0] = 4;
  aposta.dezenas[1] = 5;
  aposta.dezenas[2] = 10;
  aposta.dezenas[3] = 12;
  aposta.dezenas[4] = 14;
  aposta.dezenas[5] = 25;
  fwrite(&aposta, sizeof(struct Aposta), 1, arq);

  aposta.nroCartao = 2107;
  aposta.dezenas[0] = 1;
  aposta.dezenas[1] = 2;
  aposta.dezenas[2] = 18;
  aposta.dezenas[3] = 33;
  aposta.dezenas[4] = 49;
  aposta.dezenas[5] = 51;
  fwrite(&aposta, sizeof(struct Aposta), 1, arq);

  rewind(arq);
  int cartao = 2107;

  int *dezenas = lerDezenasDoCartao(arq, cartao);
  mostrarDezenasDoCartao(dezenas, 6);
  fclose(arq);
}
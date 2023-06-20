#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char descr[31];
  char tipo[10]; // Debito ou Credito
  float vlr;
} rgDados;

rgDados *lerLancamentos(FILE *arq, int tam)
{
  rgDados *vet = (rgDados *)malloc(sizeof(rgDados) * tam);

  int i;

  for (i = 0; i < tam; i++)
  {
    rgDados item;
    int ret = fread(&item, sizeof(rgDados), 1, arq);

    vet[i] = item;

    if (ret == 0)
      break;
  }

  return vet;
}

void mostrarLancamentos(rgDados lanctos[], int tam)
{
  int i;
  float totalCred = 0;
  float totalDeb = 0;

  for (i = 0; i < tam; i++)
  {
    rgDados item = lanctos[i];
    char tipo;

    if (item.tipo[0] == 'C')
    {
      tipo = 'C';

      totalCred += item.vlr;
    }
    else
    {
      tipo = 'D';

      totalDeb += item.vlr;
    }

    printf("%s R$ %.2f %c\n", item.descr, item.vlr, tipo);
  }

  float saldo = totalCred - totalDeb;
  char tipoSaldo = 'C';

  if (saldo < 0)
  {
    tipoSaldo = 'D';

    saldo *= -1;
  }

  printf("\nCreditos = R$ %.2f\n", totalCred);
  printf("Debitos  = R$ %.2f\n", totalDeb);
  printf("Saldo    = R$ %.2f %c\n", saldo, tipoSaldo);
}

int main()
{
  int tam = 4;
  FILE *arq;
  arq = fopen("lanctos.bin", "a+b");
  rgDados lanc;

  // 1o. lançamento
  strcpy(lanc.descr, "Salario");
  strcpy(lanc.tipo, "Credito");
  lanc.vlr = 2000.50;
  fwrite(&lanc, sizeof(rgDados), 1, arq);
  // 2o. lançamento
  strcpy(lanc.descr, "Supermercado");
  strcpy(lanc.tipo, "Debito");
  lanc.vlr = 250.44;
  fwrite(&lanc, sizeof(rgDados), 1, arq);
  // 3o. lançamento
  strcpy(lanc.descr, "Gasolina");
  strcpy(lanc.tipo, "Debito");
  lanc.vlr = 371.33;
  fwrite(&lanc, sizeof(rgDados), 1, arq);
  // 4o. lançamento
  strcpy(lanc.descr, "Aluguel");
  strcpy(lanc.tipo, "Debito");
  lanc.vlr = 1400.00;
  fwrite(&lanc, sizeof(rgDados), 1, arq);
  rewind(arq);
  rgDados *lanctos;
  lanctos = lerLancamentos(arq, tam);
  mostrarLancamentos(lanctos, tam);
  fclose(arq);
}
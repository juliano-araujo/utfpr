#include <stdio.h>
#include <stdlib.h>

typedef struct data_s
{
  int dia, mes, ano;
} data_t;

typedef struct pessoa_s
{
  int cod;
  char nome[64];
  data_t nasc;
} pessoa_t;

void read_person(pessoa_t *pessoa)
{
  scanf("%d", &pessoa->cod);
  scanf(" %[^\n]s", pessoa->nome);
  scanf("%d %d %d", &pessoa->nasc.dia, &pessoa->nasc.mes, &pessoa->nasc.ano);
}

void print_person(pessoa_t pessoa)
{
  printf("%d - %s\n", pessoa.cod, pessoa.nome);
  printf("Nascimento: %d/%d/%4d", pessoa.nasc.dia, pessoa.nasc.mes, pessoa.nasc.ano);
}

int main(void)
{
  pessoa_t p;
  read_person(&p);
  print_person(p);
}
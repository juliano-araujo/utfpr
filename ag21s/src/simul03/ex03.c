#include <stdio.h>

int main()
{
  int contHomens = 0, contMulheres = 0,
      somaIdadeHomens = 0, somaIdadeMulheres = 0;

  do
  {
    char sexo;
    int idade;

    scanf(" %c", &sexo);

    if (sexo >= 'a')
    {
      sexo = sexo - 32;
    }

    if (sexo == 'X')
    {
      break;
    }
    else if (sexo != 'F' && sexo != 'M')
    {
      printf("Sexo invalido! Informe F ou M (ou X para sair).\n");
      continue;
    }

    scanf("%d", &idade);

    if (sexo == 'M')
    {
      contHomens++;
      somaIdadeHomens += idade;
    }
    else
    {
      contMulheres++;
      somaIdadeMulheres += idade;
    }

  } while (1);

  float mediaHomens = 0, mediaMulheres = 0;

  if (contHomens > 0)
  {
    mediaHomens = somaIdadeHomens / (float)contHomens;
  }

  if (contMulheres > 0)
  {
    mediaMulheres = somaIdadeMulheres / (float)contMulheres;
  }

  printf("Total de homens: %d\n", contHomens);
  printf("Total de mulheres: %d\n", contMulheres);
  printf("Media de idade dos homens: %.2f\n", mediaHomens);
  printf("Media de idade das mulheres: %.2f\n", mediaMulheres);

  if (contHomens != 0 || contMulheres != 0)
  {
    if (contHomens == 0)
    {
      printf("O sexo feminino cuida da beleza mais cedo.");
    }
    else if (contMulheres == 0)
    {
      printf("O sexo masculino cuida da beleza mais cedo.");
    }
    else
    {
      if (mediaHomens < mediaMulheres)
      {
        printf("O sexo masculino cuida da beleza mais cedo.");
      }
      else if (mediaHomens > mediaMulheres)
      {
        printf("O sexo feminino cuida da beleza mais cedo.");
      }
      else
      {
        printf("Os sexos feminino e masculino cuidam da beleza com a mesma media de idade.");
      }
    }
  }
}

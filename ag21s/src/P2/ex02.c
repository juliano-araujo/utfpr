#include <stdio.h>

int main()
{
  int i, n, fem = 0, masc = 0;
  float somaFem = 0, somaMasc = 0;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    char sexo;
    int idade;

    scanf(" %c %d", &sexo, &idade);

    if (sexo >= 'a')
    {
      sexo -= 32;
    }

    if (sexo == 'F')
    {
      fem++;
      somaFem += idade;
    }
    else if (sexo == 'M')
    {
      masc++;
      somaMasc += idade;
    }
  }

  printf("Atletas do sexo feminino: %d\n", fem);
  printf("Atletas do sexo masculino: %d\n", masc);

  if (fem > 0)
  {
    float media = somaFem / (float)fem;
    printf("Media de idade sexo feminino: %.3f\n", media);
  }

  if (masc > 0)
  {
    float media = somaMasc / (float)masc;
    printf("Media de idade sexo masculino %.3f\n", media);
  }
}
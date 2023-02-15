#include <stdio.h>

int main()
{
  char user_type;
  int senha;

  scanf("%c", &user_type);
  scanf("%d", &senha);

  switch (user_type)
  {
  case 'A':
  case 'D':
    if (senha == 555)
    {
      printf("Acesso ADMIN");
    }
    else
    {
      printf("Acesso NEGADO");
    }
    break;
  case 'U':
    if (senha == 123)
    {
      printf("Acesso USER");
    }
    else
    {
      printf("Acesso NEGADO");
    }
    break;
  default:
    printf("Acesso NEGADO");
  }
}
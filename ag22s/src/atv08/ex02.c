#include <stdio.h>

int multiplicacao_recursiva(int v1, int v2)
{
  if (v1 == 1)
  {
    return v2;
  }

  return v2 + multiplicacao_recursiva(v1 - 1, v2);
}

int main(void)
{
  int v1, v2;
  scanf("%d %d", &v1, &v2);
  printf("Multiplicacao recursiva: %d", multiplicacao_recursiva(v1, v2));
}

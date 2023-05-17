#include <stdio.h>

char string[100];

void inverter(int n)
{
  if (string[n] == '\0')
  {
    return;
  }

  inverter(n + 1);
  printf("%c", string[n]);
}

int main()
{
  scanf("%s", string);
  inverter(0);
}
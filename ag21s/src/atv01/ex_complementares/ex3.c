#include <stdio.h>
int main()
{
  int horas, minutos;

  scanf("%d", &horas);
  scanf("%d", &minutos);

  int total_minutos = (horas * 60) + minutos;

  printf("Passaram %d minutos.", total_minutos);
}
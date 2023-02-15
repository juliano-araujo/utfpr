#include <stdio.h>
int main()
{
  int numero;

  scanf("%d", &numero);

  printf("01x%.2d = %.2d\n", numero, numero * 1);
  printf("02x%.2d = %.2d\n", numero, numero * 2);
  printf("03x%.2d = %.2d\n", numero, numero * 3);
  printf("04x%.2d = %.2d\n", numero, numero * 4);
  printf("05x%.2d = %.2d\n", numero, numero * 5);
  printf("06x%.2d = %.2d\n", numero, numero * 6);
  printf("07x%.2d = %.2d\n", numero, numero * 7);
  printf("08x%.2d = %.2d\n", numero, numero * 8);
  printf("09x%.2d = %.2d\n", numero, numero * 9);
  printf("10x%.2d = %.2d", numero, numero * 10);
}
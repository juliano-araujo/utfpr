#include <stdio.h>

int main()
{
  int n, i;

  scanf("%d", &n);

  double vet[n];

  for (i = 0; i < n; i++)
  {
    scanf("%lf", &vet[i]);
  }

  for (i = n - 1; i >= 0; i--)
  {
    printf("%.1lf\n", vet[i]);
  }
}
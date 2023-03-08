#include <stdio.h>

int main(void)
{
  int n, i;
  float x;

  scanf("%d", &n);

  float arr[n];

  for (i = 0; i < n; i++)
  {
    scanf("%f", &arr[i]);
  }

  scanf("%f", &x);

  for (i = 0; i < n; i++)
  {
    if (arr[i] < x)
    {
      printf("V[%d] = %.2f \n", i, arr[i]);
    }
  }

  return 0;
}
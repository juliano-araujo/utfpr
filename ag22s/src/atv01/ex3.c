#include <stdio.h>

int main(void)
{
  int n, i;

  scanf("%d", &n);

  int arr[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n; i++)
  {
    if (arr[i] % 2 == 0)
    {
      printf("V[%d] = %d \n", i, arr[i]);
    }
  }

  return 0;
}
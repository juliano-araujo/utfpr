#include <stdio.h>

int main()
{
  int num, i = 1;

  scanf("%d", &num);

  while (i <= num)
  {
    int j = 0;
    do
    {
      if (j < i)
      {
        printf("- ");
      }
      else
      {
        printf("%d ", i);
      }
      j++;
    } while (j < num);

    printf("\n");
    i++;
  }
}

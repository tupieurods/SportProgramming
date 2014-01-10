#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int m = 31;
  int a[m + 2][m + 2];
  memset(a, 0, sizeof(int) * (m + 2) * (m + 2));
  for(int j = 1; j <= m + 1; j++)
    a[1][j] = 0;
  a[1][m + 1] = 1;
  for(int i = 2; i <= m + 1; i++)
  {
    for(int j = 1; j <= m + 1; j++)
    {
      if(j == 1)
      {
        a[i][j] = a[i - 1][j + 1];
      }
      else if(j == (m + 1))
      {
        a[i][j] = a[i - 1][j - 1];
      }
      else
      {
        a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j + 1];
      }
    }
  }
  for(int i = 1; i <= m + 1; i++)
  {
    for(int j = 1; j <= m + 1; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}

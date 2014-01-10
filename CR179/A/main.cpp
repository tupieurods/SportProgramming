#include <stdio.h>
#include <string.h>

using namespace std;

inline int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int a[1001];
  memset(a, 0, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    a[tmp]++;
  }
  int maximal = a[1];
  for(int i = 2; i < 1001; i++)
  {
    maximal = max(maximal, a[i]);
  }
  /*if(n <= 2)
  {
    if(n == 1)
    {
      printf("YES");
      return 0;
    }
    else
    {
      if(maximal == 1)
      {
        printf("YES");
      }
      else
      {
        printf("NO");
      }
    }
  }*/
  int half = n / 2;
  if(n % 2 == 1)
    half++;
  if(maximal > half)
  {
    printf("NO");
  }
  else
  {
    printf("YES");
  }
  return 0;
}

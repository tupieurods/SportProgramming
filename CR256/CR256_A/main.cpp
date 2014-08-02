#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n, val, a = 0, b = 0;
    for(int i = 0; i < 3; i++)
    { 
      scanf("%d", &val);
      a += val;
    }
    for(int i = 0; i < 3; i++)
    { 
      scanf("%d", &val);
      b += val;
    }
    scanf("%d", &n);
    val = (a / 5 + (a % 5 == 0 ? 0 : 1)) + (b / 10 + (b % 10 == 0 ? 0 : 1));
    if(val <= n)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int a[1000009];

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  int n;
  scanf("%d", &n);
  int pos = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    for(int j = 0; j < val; j++)
    {
      a[pos] = i;
      pos++;
    }
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    printf("%d\n", a[val - 1] + 1);
  }
  return 0;
}
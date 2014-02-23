#include <stdio.h>

int main()
{
  int n, m, y;
  scanf("%d %d %d", &n, &m, &y);
  int cnt = 0;
  for(int i = 0; i < m; i++)
  {
    int num = i == 0 ? 0 : 1;
    for(int j = 0; j < n; j++)
    {
      num *= i;
      num %= m;
    }
    if(num == y)
    {
      cnt++;
      printf("%d ", i);
    }
  }
  if(cnt == 0)
  {
    printf("-1\n");
  }
  return 0;
}
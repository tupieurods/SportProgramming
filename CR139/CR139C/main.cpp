#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

const __int64 myInf = 10000000000LL;

int n, m, x, y;
__int64 a[1000];
__int64 dp[1000][2009];

void ReadData()
{
  memset(a, 0, sizeof(a));
  scanf("%d %d %d %d%*c", &n, &m, &x, &y);
  char str[1009];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", &str);
    for(int j = 0; j < m; j++)
    {
      if(str[j] == '#')
        a[j]++;
    }
  }
}

__int64 answer;

__int64 f(int column, int cnt)
{
  bool zero = cnt >= 1001;
  int realCnt = cnt >= 1001 ? cnt - 1001 : cnt;
  if(column == m)
  {
    if(realCnt >= x && realCnt <= y)
      return 0LL;
    return myInf;
  }
  if(dp[column][cnt] != -1)
    return dp[column][cnt];
  __int64 result = myInf;
  if(realCnt < y)
  {
    result = std::min(result,
      (zero ? a[column] : n - a[column]) + f(column + 1, cnt + 1));
    if(realCnt >= x)
    {
      result = std::min(result,
        (zero ? n - a[column] : a[column]) + f(column + 1, (zero ? 1 : 1002)));;
    }
  }
  else
  {
    result = std::min(result,
      (zero ? n - a[column] : a[column]) + f(column + 1, (zero ? 1 : 1002)));
  }
  dp[column][cnt] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answer = std::min(f(0, 0), f(0, 1001));
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1000 1000 1 1000\n");
    for(int i = 0; i < 1000; i++)
    {
      for(int j = 0; j < 1000; j++)
      {
        printf("#");
      }
      printf("\n");
    }
    return 0;
  }
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ReadData();
  Solve();
  WriteData();
}
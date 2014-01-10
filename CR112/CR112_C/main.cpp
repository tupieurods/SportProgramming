#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;
char str[1000009];

void ReadData()
{
  scanf("%d%*c", &k);
  scanf("%s%*c", str);
}

__int64 answer;
__int64 sums[1000009];

void Solve()
{
  int n = strlen(str);
  memset(sums, 0, sizeof(sums));
  int sum = 0LL;
  answer = 0;
  sums[0] = 1;
  for(int i = 0; i < n; i++)
  {
    sum += (int)(str[i] - '0');
    if(sum - k >= 0)
    {
      answer += sums[sum - k];
    }
    sums[sum]++;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
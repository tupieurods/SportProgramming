#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, k;
int a[1009];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i <= m; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < m; i++)
  {
    int copy = a[m] ^ a[i];
    int current = 0;
    while(copy != 0)
    {
      if((copy & 1) != 0)
      {
        current++;
      }
      copy >>= 1;
    }
    if(current <= k)
    {
      answer++;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
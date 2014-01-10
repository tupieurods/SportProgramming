#include <stdio.h>
#include <stdlib.h>

int n, m;

void ReadData()
{
  scanf("%d %d", &n, &m);
}

__int64 answer;

void Solve()
{
  answer = 0;
  int current;
  scanf("%d", &current);
  if(current != 1)
  {
    answer = current - 1;
  }
  for(int i = 1; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    if(val > current)
    {
      answer += val - current;
    }
    else if(val < current)
    {
      answer += n - current + val;
    }
    current = val;
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
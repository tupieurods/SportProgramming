#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;

void ReadData()
{
  scanf("%d %d", &n, &m);
}

int answer;

void Solve()
{
  for(answer = m; answer < 100000; answer += m)
  {
    if(answer > n)
    {
      answer = -1;
      break;
    }
    for(int i = 0; i <= answer; i++)
    {
      if((i + (answer - i) * 2) == n)
      {
        return;
      }
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

//#define LOCAL

int n, m, t, c;
char judge[109][109];

void ReadData()
{
  scanf("%d %d %d %d%*c", &n, &m, &t, &c);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", judge[i]);
  }
}

int answer;

void Solve()
{
  int idx = 0;
  answer = -c;
  while(idx < m)
  {
    int bestIdx = 0, best = 0;
    for(int i = 0; i < n; i++)
    {
      int current = 0;
      for(int j = idx; j < m; j++)
      {
        if(judge[i][j] == '1')
        {
          current++;
          continue;
        }
        break;
      }
      if(current > best)
      {
        bestIdx = i;
        best = current;
      }
    }
    answer += best * t + c;
    idx += best;
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
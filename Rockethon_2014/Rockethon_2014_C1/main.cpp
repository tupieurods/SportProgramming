#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int p[20], e[20];
int pWork[20];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &p[i], &e[i]);
  }
}

int answer;

void Solve()
{
  answer = INT_MAX;
  int cnt = 1 << n;
  for(int mask = 0; mask < cnt; mask++)
  {
    int copy = mask;
    int index = 0;
    int current = 0;
    int wins = 0;
    for(int i = 0; i < n; i++)
    {
      pWork[i] = p[i] + 1;
    }
    while(copy != 0)
    {
      if((copy & 1) != 0)
      {
        pWork[index]--;
        wins++;
        current += e[index];
      }
      /*if((copy & 1) == 0)
      {
        pWork[index]++;
      }
      else
      {
        wins++;
        current += e[index];
      }*/
      index++;
      copy >>= 1;
    }
    int pos = n + 1;
    for(int i = 0; i < n; i++)
    {
      if(pWork[i] < wins)
      {
        pos--;
      }
      else if((pWork[i] == wins) && ((mask & (1 << i)) != 0))
      {
        pos--;
      }
    }
    if(pos <= k)
    {
      answer = min(answer, current);
    }
  }
  if(answer == INT_MAX)
  {
    answer = -1;
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
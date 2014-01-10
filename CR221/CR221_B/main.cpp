#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m;
int balance[109];

void ReadData()
{
  scanf("%d %d", &n, &m);
}

int answer;

void Solve()
{
  memset(balance, 0, sizeof(balance));
  for(int i = 0; i < m; i++)
  {
    int f, t, c;
    scanf("%d %d %d", &f, &t, &c);
    f--;
    t--;
    balance[f] -= c;
    balance[t] += c;
  }
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    if(balance[i] < 0)
    {
      answer -= balance[i];
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
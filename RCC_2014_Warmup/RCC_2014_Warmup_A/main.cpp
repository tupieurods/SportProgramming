#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int c, d, n, m, k;
int cnt;

void ReadData()
{
  scanf("%d %d", &c, &d);
  scanf("%d %d", &n, &m);
  scanf("%d", &k);
}

int answer;

void Solve()
{
  answer = INT_MAX;
  for(int shit = 0; shit <= k; shit++)
  {
    cnt = n * m - shit;
    if(cnt < 0)
    {
      continue;
    }
    int c1 = cnt / n;
    int c2 = cnt % n;
    answer = std::min(c1 * c + c2 * d, answer);
    while(c1 != 0)
    {
      c1--;
      c2 += n;
      answer = std::min(c1 * c + c2 * d, answer);
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
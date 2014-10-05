#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k;
int f[2009];

void ReadData()
{
  memset(f, 0, sizeof(f));
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    f[val]++;
  }
}

int answer;

void Solve()
{
  answer = 0;
  int total = n;
  int idx = 2001;
  while(total != 0)
  {
    int current = k;
    int plus = 0;
    while(current != 0 && total != 0)
    {
      while(f[idx] == 0)
      {
        idx--;
      }
      int minus = std::min(f[idx], current);
      f[idx] -= minus;
      current -= minus;
      total -= minus;
      plus = std::max(plus, idx);
    }
    answer += (plus - 1) * 2;
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
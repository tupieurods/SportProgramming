#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
int c[10009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
  }
}

int answer;

void Solve()
{
  std::sort(c, c + n);
  answer = 0;
  int l = 0, r = n - 1;
  while(l <= r)
  {
    answer++;
    int sum = m - c[r];
    r--;
    if((r >= l) && (c[r] <= sum))
    {
      r--;
    }
    else if((l <= r) && (c[l] <= sum))
    {
      l++;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
}
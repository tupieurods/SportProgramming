#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows[1009], cols[1009];
int n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
  memset(rows, 0, sizeof(rows));
  memset(cols, 0, sizeof(cols));
  for(int i = 0; i < k; i++)
  {
    int r, c;
    scanf("%d %d", &c, &r);
    cols[c - 1] = 1;
    rows[r - 1] = 1;
  }
}

int answer;

void Solve()
{
  answer = 0;
  int cnt = n / 2;
  for(int i = 1; i < cnt; i++)
  {
    if(rows[i] == 0)
      answer++;
    if(cols[i] == 0)
      answer++;
    if(rows[n - 1 - i] == 0)
      answer++;
    if(cols[n - 1 - i] == 0)
      answer++;
  }
  if(n % 2 == 1)
  {
    if(cols[n / 2] == 0 || rows[n / 2] == 0)
      answer++;
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
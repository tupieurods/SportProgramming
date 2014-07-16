#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, p;

void ReadData()
{
  scanf("%d %d", &p, &n);
}

int answer;
bool table[309];

void Solve()
{
  answer = -1;
  memset(table, 0, sizeof(table));
  for(int i = 0; i < n; i++)
  {
    int X;
    scanf("%d", &X);
    int h = X % p;
    if(table[h] && answer == -1)
    {
      answer = i + 1;
    }
    table[h] = true;
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
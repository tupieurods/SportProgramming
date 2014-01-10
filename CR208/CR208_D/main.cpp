#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int a[3009], b[3009], c[3009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
  }
}

int answer;
int dp0[3009], dp1[3009];

int f1(int index);

int f0(int index)
{
  if(dp0[index] == -1)
  {
    dp0[index] = std::max(a[index] + f1(index + 1), b[index] + f0(index + 1));
  }
  return dp0[index];
}

int f1(int index)
{
  if(dp1[index] == -1)
  {
    dp1[index] = std::max(b[index] + f1(index + 1), c[index] + f0(index + 1));
  }
  return dp1[index];
}

void Solve()
{
  memset(dp0, 0xFF, sizeof(dp0));
  dp0[n - 1] = a[n - 1];
  memset(dp1, 0xFF, sizeof(dp1));
  dp1[n - 1] = b[n - 1];
  answer = f0(0);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
bool a[200009];
int l, r;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a[i] = val == 1;
    if(a[i])
    {
      r++;
    }
    else
    {
      l++;
    }
  }
}

__int64 answer;

void Solve()
{
  answer = 1LL << 62;
  __int64 c1 = 0, c2 = 0;
  int cl = l, cr = r;
  for(int i = 0; i < n; i++)
  {
    if(a[i])
    {
      c1 += l;
      r--;
    }
    else
    {
      l--;
    }
  }
  l = cl;
  r = cr;
  for(int i = n - 1; i >= 0; i--)
  {
    if(a[i] == false)
    {
      c2 += r;
      l--;
    }
    else
    {
      r--;
    }
  }
  answer = std::min(c1, c2);
}

void WriteData()
{
  printf("%I64d\n", answer);
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
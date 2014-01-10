#include <stdio.h>

//#define LOCAL

int n, l;

void ReadData()
{
  scanf("%d %d", &n, &l);
}

int a, b;

void Solve()
{
  a = 0, b = 0;
  for(int i = 0; i < n; i++)
  {
    int t, d;
    scanf("%d %d", &t, &d);
    int toAdd = 0;
    if(d == -1)
    {
      toAdd = 1;
    }
    else if(d <= l)
    {
      toAdd = 2;
    }
    else
    {
      toAdd = 3;
    }
    if(t == 1)
    {
      a += toAdd;
    }
    else
    {
      b += toAdd;
    }
  }
}

void WriteData()
{
  printf("%d:%d\n", a, b);
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
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
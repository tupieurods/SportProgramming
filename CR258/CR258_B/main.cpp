#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int a[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int la, ra;

void Solve()
{
  la = -1, ra = -1;
  int current = -1;
  for(int i = 0; i < n - 1; i++)
  {
    if(a[i] > a[i + 1])
    {
      if(ra != -1)
      {
        la = ra = -1;
        return;
      }
      if(la == -1)
      {
        la = i;
      }
      current = i + 1;
    }
    else if(la != -1 && ra == -1)
    {
      ra = current;
    }
  }
  if(la != -1 && ra == -1)
  {
    ra = current;
  }
  if(la == -1)
  {
    la = ra = 0;
    return;
  }
  int cnt = 0;
  if(la == 0)
  {
    cnt++;
  }
  if(ra == n - 1)
  {
    cnt++;
  }
  if(la != 0 && a[la - 1] < a[ra])
  {
    cnt++;
  }
  if(ra != n - 1 && a[la] < a[ra + 1])
  {
    cnt++;
  }
  if(cnt != 2)
  { 
    la = ra = -1;
  }
}

void WriteData()
{
  if(la != -1)
  {
    printf("yes\n%d %d\n", la + 1, ra + 1);
  }
  else
  {
    printf("no\n");
  }
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
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

int n;
int a[109], b[109], sa, sb;

void ReadData()
{
  scanf("%d", &n);
  sa = 0;
  sb = 0;
  for(int i = 0; i < n; i++)
  {
    int l, r;
    scanf("%d %d", &a[i], &b[i]);
    sa += a[i];
    sb += b[i];
  }
}

int answer;

void Solve()
{
  answer = -1;
  if(sa % 2 == 0 && sb % 2 == 0)
  {
    answer = 0;
    return;
  }
  for(int i = 0; i < n; i++)
  {
    if((sa - a[i] + b[i]) % 2 == 0
       && (sb - b[i] + a[i]) % 2 ==0)
    {
      answer = 1;
      return;
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
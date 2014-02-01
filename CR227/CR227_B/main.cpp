#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
int a[3009], b[3009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
}

int answer;

void Solve()
{
  std::sort(a, a + n);
  std::sort(b, b + m);
  answer = n;
  int l = 0, r = m - 1;
  int l2 = 0;
  for(; l2 < m && l < n; l2++)
  {
    if(a[l] <= b[l2])
    {
      answer--;
      l++;
    }
  }
  /*int bInd = l;
  while(true)
  {
    if(r < bInd || l >= n)
    {
      break;
    }
    if(b[r] >= a[l])
    {
      answer--;
      r--;
      l++;
    }
    else
    {
      break;
    }
  }*/
}

void WriteData()
{
  printf("%d\n", answer);
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
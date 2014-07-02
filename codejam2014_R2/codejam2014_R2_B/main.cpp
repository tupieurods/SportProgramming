#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, imax;
int a[1009], b[1009];

void ReadData()
{
  scanf("%d", &n);
  imax = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;

void Solve()
{
  answer = 0;
  int l = 0, r = n - 1;
  while(l != r)
  {
    int idx = l;
    for(int i = l; i <= r; i++)
    {
      if(a[idx] > a[i])
      {
        idx = i;
      }
    }
    int delta = r - idx < idx - l ? 1 : -1;
    int last = delta == 1 ? r : l;
    while(idx != last)
    {
      std::swap(a[idx], a[idx + delta]);
      idx += delta;
      answer++;
    }
    if(last == r)
    {
      r--;
    }
    else
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
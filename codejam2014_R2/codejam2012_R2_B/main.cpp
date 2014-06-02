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
    if(a[i] > a[imax])
    {
      imax = i;
    }
  }
}

int answer;

void Solve()
{
  answer = INT_MAX;
  for(int m = 0; m < n; m++)
  {
    memcpy(b, a, n * sizeof(int));
    int current = 0;
    if(imax > m)
    {
      for(int i = imax; i > m; i--)
      {
        std::swap(b[i], b[i - 1]);
        current++;
      }
    }
    else if(imax < m)
    {
      for(int i = imax; i < m; i++)
      {
        std::swap(b[i], b[i + 1]);
        current++;
      }
    }
    for(int i = 0; i < m; i++)
    {
      for(int j = m - 1; j > i; j--)
      {
        if (b[j - 1] > b[j])
        {
          std::swap(b[j - 1], b[j]);
          current++;
        }
      }
    }
    for(int i = m; i < n; i++)
    {
      for(int j = n - 1; j > i; j--)
      {
        if (b[j - 1] < b[j])
        {
          std::swap(b[j - 1], b[j]);
          current++;
        }
      }
    }
    answer = std::min(answer, current);
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
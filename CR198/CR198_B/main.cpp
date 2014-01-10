#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
  int x, y;
};

int n;
point a[309];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &a[i].x, &a[i].y);
  }
}

int answer;

int triangleArea(int p1I, int p2I, int p3I)
{
  return (a[p2I].x - a[p1I].x) * (a[p3I].y - a[p1I].y)
    - (a[p3I].x - a[p1I].x) * (a[p2I].y - a[p1I].y);
}

void Solve()
{
  answer = -1.0;
  for(int i = 0; i < n; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      int sPositive = -1, sNegative = -1;
      for(int k = 0; k < n; k++)
      {
        if(k == i || k == j)
        {
          continue;
        }
        int val = triangleArea(i, j, k);
        if(val < 0)
        {
          if(-val > sNegative)
          {
            sNegative = -val;
          }
        }
        else
        {
          if(val > sPositive)
          {
            sPositive = val;
          }
        }
      }
      if(sPositive != -1 && sNegative != -1
          && sPositive + sNegative > answer)
      {
        answer = sPositive + sNegative;
      }
    }
  }
  //answer /= 2.0;
}

void WriteData()
{
  printf("%.12lf\n", answer / 2.0);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int p, q, l, r;
pair<int, int> a[59], c[59];

void ReadData()
{
  scanf("%d %d %d %d", &p, &q, &l, &r);
  for(int i = 0; i < p; i++)
  {
    scanf("%d %d", &a[i].first, &a[i].second);
  }
  for(int i = 0; i < q; i++)
  {
    scanf("%d %d", &c[i].first, &c[i].second);
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(; l <= r; l++)
  {
    bool flag = false;
    for(int i = 0; i < p; i++)
    {
      for(int j = 0; j < q; j++)
      {
        if((c[j].first + l <= a[i].second && c[j].second + l >= a[i].second)
          || (c[j].first + l >= a[i].second && c[j].second + l <= a[i].second)
          || (c[j].first + l <= a[i].second && c[j].second + l >= a[i].first))
        {
          flag = true;
          answer++;
          break;
        }
      }
      if(flag)
      {
        break;
      }
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
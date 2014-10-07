#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

pair<int, int> p[4][4];
pair<int, int> basePoints[4];

void ReadData()
{
  for(int i = 0; i < 4; i++)
  {
    scanf("%d %d", &p[i][0].first, &p[i][0].second);
    scanf("%d %d", &basePoints[i].first, &basePoints[i].second);
  }
}

int answer;

inline __int64 p2(int val)
{
  return val * 1LL * val;
}

pair<int, int> cp[4];

__int64 getDist(int idx1, int idx2)
{
  __int64 _x = cp[idx1].first - cp[idx2].first;
  __int64 _y = cp[idx1].second - cp[idx2].second;
  return _x * _x + _y * _y;
}

__int64 getScalarMul(int idx1, int idx2, int MainPoint)
{
  __int64 _x1 = cp[idx1].first - cp[MainPoint].first;
  __int64 _y1 = cp[idx1].second - cp[MainPoint].second;
  __int64 _x2 = cp[idx2].first - cp[MainPoint].first;
  __int64 _y2 = cp[idx2].second - cp[MainPoint].second;
  return _x1 * _x2 + _y1 * _y2;
}

bool check(int i1, int i2, int i3, int i4)
{
  /*__int64 s1 = p2(p[0][i1].first - p[1][i2].first) + p2(p[0][i1].second - p[1][i2].second);

  __int64 s2 = p2(p[0][i1].first - p[2][i3].first) + p2(p[0][i1].second - p[2][i3].second);

  __int64 s3 = p2(p[0][i1].first - p[3][i4].first) + p2(p[0][i1].second - p[3][i4].second);

  __int64 s4 = p2(p[1][i2].first - p[2][i3].first) + p2(p[1][i2].second - p[2][i3].second);

  __int64 s5 = p2(p[1][i2].first - p[3][i4].first) + p2(p[1][i2].second - p[3][i4].second);

  __int64 s6 = p2(p[2][i3].first - p[3][i4].first) + p2(p[2][i3].second - p[3][i4].second);

  return (s1 != 0 && s2 != 0 && s3 != 0 && s4 != 0 && s5 != 0 && s6 != 0)
    && ((s1 == s3 && s3 == s4 && s4 == s6 && s2 == s5 && s5 == 2LL * s1)

      || (s1 == s2 && s2 == s5 && s5 == s6 && s3 == s4 && s4 == 2LL * s1)

      || (s1 == s3 && s3 == s4 && s4 == s5 && s1 == s6 && s6 == 2LL * s2));*/
  cp[0] = p[0][i1];
  cp[1] = p[1][i2];
  cp[2] = p[2][i3];
  cp[3] = p[3][i4];
  __int64 minL = _I64_MAX;
  for(int i = 0; i < 4; i++)
  {
    for(int j = i + 1; j < 4; j++)
    {
      minL = min(minL, getDist(i ,j));
    }
  }
  if(minL == 0)
  {
    return false;
  }
  int near[2];
  int nearCnt;
  for(int i = 0; i < 4; i++)
  {
    nearCnt = 0;
    for(int j = 0; j < 4; j++)
    {
      if(i == j)
      {
        continue;
      }
      if(getDist(i, j) == minL)
      {
        if(nearCnt == 2)
        {
          return false;
        }
        near[nearCnt++] = j;
      }
    }
    if(nearCnt != 2)
    {
      return false;
    }
    if(getScalarMul(near[0], near[1], i) != 0)
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  answer = 10000;
  for(int T = 0; T < 4; T++)
  {
    for(int i = 1; i < 4; i++)
    {
      p[T][i].first = p[T][i - 1].first - basePoints[T].first;
      p[T][i].second = p[T][i - 1].second - basePoints[T].second;
      swap(p[T][i].first, p[T][i].second);
      p[T][i].first *= -1;
      p[T][i].first += basePoints[T].first;
      p[T][i].second += basePoints[T].second;
    }
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      for(int k = 0; k < 4; k++)
      {
        for(int m = 0; m < 4; m++)
        {
          /*if(i == 0 && j == 1 && k == 0 && m == 0)
          {
            printf("!");
          }*/
          if(check(i, j, k, m))
          {
            answer = min(answer, i + j + k + m);
          }
        }
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer == 10000 ? -1 : answer);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  int QWE = 1;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
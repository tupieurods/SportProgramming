#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int dots[8][3], p[8][3];

void ReadData()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      scanf("%d", &dots[i][j]);
    }
  }
}

__int64 getDist(int idx1, int idx2)
{
  __int64 _x = p[idx2][0] - p[idx1][0];
  __int64 _y = p[idx2][1] - p[idx1][1];
  __int64 _z = p[idx2][2] - p[idx1][2];
  return _x * _x + _y * _y + _z * _z;
}

__int64 getScalarMul(int idx1, int idx2, int MainPoint)
{
  __int64 _x1 = p[idx1][0] - p[MainPoint][0];
  __int64 _y1 = p[idx1][1] - p[MainPoint][1];
  __int64 _z1 = p[idx1][2] - p[MainPoint][2];
  __int64 _x2 = p[idx2][0] - p[MainPoint][0];
  __int64 _y2 = p[idx2][1] - p[MainPoint][1];
  __int64 _z2 = p[idx2][2] - p[MainPoint][2];
  return _x1 * _x2 + _y1 * _y2 + _z1 * _z2;
}

bool check()
{
  __int64 minL = _I64_MAX;
  for(int i = 0; i < 8; i++)
  {
    for(int j = i + 1; j < 8; j++)
    {
      minL = std::min(minL, getDist(i ,j));
    }
  }
  if(minL == 0)
  {
    return false;
  }
  int near[3];
  int nearCnt;
  for(int i = 0; i < 8; i++)
  {
    nearCnt = 0;
    for(int j = 0; j < 8; j++)
    {
      if(i == j)
      {
        continue;
      }
      if(getDist(i, j) == minL)
      {
        if(nearCnt == 3)
        {
          return false;
        }
        near[nearCnt++] = j;
      }
    }
    if(nearCnt != 3)
    {
      return false;
    }
    if(getScalarMul(near[0], near[1], i) != 0 || getScalarMul(near[2], near[1], i) != 0
      || getScalarMul(near[0], near[2], i) != 0)
    {
      return false;
    }
  }
  return true;
}

bool answer;
int perm[6][3] = {
  {0, 1, 2},
  {0, 2, 1},
  {1, 0, 2},
  {1, 2, 0},
  {2, 1, 0},
  {2, 0, 1}
};

int pIdx[8];

void SetP(int idx)
{
  p[idx][0] = dots[idx][perm[pIdx[idx]][0]];
  p[idx][1] = dots[idx][perm[pIdx[idx]][1]];
  p[idx][2] = dots[idx][perm[pIdx[idx]][2]];
}

void Solve()
{
  answer = false;
  p[7][0] = dots[7][0];
  p[7][1] = dots[7][1];
  p[7][2] = dots[7][2];
  //No recursion, i wanna copy-paste
  for(pIdx[0] = 0; pIdx[0] < 6; pIdx[0]++)
  {
    SetP(0);
    for(pIdx[1] = 0; pIdx[1] < 6; pIdx[1]++)
    {
      SetP(1);
      for(pIdx[2] = 0; pIdx[2] < 6; pIdx[2]++)
      {
        SetP(2);
        for(pIdx[3] = 0; pIdx[3] < 6; pIdx[3]++)
        {
          SetP(3);
          for(pIdx[4] = 0; pIdx[4] < 6; pIdx[4]++)
          {
            SetP(4);
            for(pIdx[5] = 0; pIdx[5] < 6; pIdx[5]++)
            {
              SetP(5);
              for(pIdx[6] = 0; pIdx[6] < 6; pIdx[6]++)
              {
                SetP(6);
                /*for(pIdx[7] = 0; pIdx[7] < 6; pIdx[7]++)
                {*/
                  //SetP(7);
                  /*if((p[0][0] == 0 && p[0][1] == 0 && p[0][2] == 0)
                   && (p[1][0] == 0 && p[1][1] == 0 && p[1][2] == 1)
                   && (p[2][0] == 0 && p[2][1] == 1 && p[2][2] == 0)
                   && (p[3][0] == 1 && p[3][1] == 0 && p[3][2] == 0)
                   && (p[4][0] == 0 && p[4][1] == 1 && p[4][2] == 1)
                   && (p[5][0] == 1 && p[5][1] == 0 && p[5][2] == 1)
                   && (p[6][0] == 1 && p[6][1] == 1 && p[6][2] == 0)
                   && (p[7][0] == 1 && p[7][1] == 1 && p[7][2] == 1))
                  {
                    printf("Surprise Neo");
                  }*/
                  if(check())
                  {
                    answer = true;
                    return;
                  }
                //}
              }
            }
          }
        }
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < 8; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        printf("%d ", p[i][j]);
      }
      printf("\n");
    }
    printf("\n");
  }
  else
  {
    printf("NO\n");
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
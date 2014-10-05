#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int x, k;
long double p;

void ReadData()
{
  scanf("%d %d %lf", &x, &k, &p);
}

const int firstBitsCnt = 8;

long double answer;
long double dp[2][(1 << (firstBitsCnt + 1))][2][409];

void Solve()
{
  p /= 100.0;
  answer = 0;
  int firstBits = (1 << (firstBitsCnt + 1)) - 1;
  int xMask = x & firstBits;
  int xLast = (x & (1 << (firstBitsCnt + 1))) > 0 ? 1 : 0;
  int xCnt = 0;

  x >>= firstBitsCnt + 1;
  if(x == 0)
  {
    xCnt = 200;
  }
  else
  {
    while(true)
    {
      if((x & 1) == xLast)
      {
        xCnt++;
      }
      else
      {
        break;
      }
      x >>= 1;
    }
  }
  int current = 1;
  int prev = 0;
  memset(dp, 0, sizeof(dp));
  dp[prev][xMask][xLast][xCnt] = 1.0;

  for(int T = 0; T < k; T++)
  {
    memset(dp[current], 0, sizeof(dp[current]));
    for(int mask = 0; mask < (1 << (firstBitsCnt + 1)); mask++)
    {
      for(int last = 0; last < 2; last++)
      {
        for(int cnt = 0; cnt < 402; cnt++)
        {
          long double dpPrev = dp[prev][mask][last][cnt];

          //x2
          {
            int nmask = (mask << 1) & firstBits;
            int nlast = (mask & (1 << firstBitsCnt)) > 0 ? 1 : 0;
            int ncnt = nlast == last ? cnt + 1 : 1;
            dp[current][nmask][nlast][ncnt] += dpPrev * p;
          }

          //+1
          {
            int nmask = mask + 1;

            if(nmask != (1 << (firstBitsCnt + 1)))
            {
              dp[current][nmask][last][cnt] += dpPrev * (1.0 - p);
            }
            else
            {
              if(last == 1)
              {
                dp[current][0][0][cnt + 1] += dpPrev * (1.0 - p);
              }
              else
              {
                dp[current][0][1][1] += dpPrev * (1.0 - p);
              }
            }
          }
        }
      }
    }
    std::swap(prev, current);
  }

  for(int mask = 0; mask < (1 << (firstBitsCnt + 1)); mask++)
  {
    for(int last = 0; last < 2; last++)
    {
      for(int cnt = 0; cnt < 402; cnt++)
      {
        int counter = 0;
        int copy = mask;
        if (copy != 0)
        {
          while (copy % 2 == 0)
          {
            counter++;
            copy /= 2;
          }
        }
        else
        {
          counter = firstBitsCnt + 1;
          if (last == 0)
          {
            counter += cnt;
          }
        }

        answer += (long double)counter * (long double)dp[prev][mask][last][cnt];
      }
    }
  }
}

void WriteData()
{
  printf("%.15lf\n", answer);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <time.h>

int p, q;

void ReadData()
{
  scanf("%d %d", &p, &q);
}

int answer, cnt;

void Solve()
{
  cnt = q - p + 1;
  answer = 0;
  int lastBit = 1 << 23;
  /*if(q < lastBit)
  {
  return;
  }*/
  if(p < lastBit)
  {
    p = lastBit;
  }
  for(int i = 0; i < lastBit; i++)
  {
    int current = (lastBit | i);
    for(int j = 1; j <= 7; j++)
    {
      current <<= 1;
      if(current > q)
      {
        break;
      }
      int l = 1, r = (1 << j) - 1;
      while(r - l > 8)
      {
        int mid = (l + r) / 2;
        if((current | mid) <= q)
        {
          l = mid;
        }
        else
        {
          r = mid;
        }
      }
      int topLevel = -1;
      for(int k = r; k >= l; k--)
      {
        if((current | k) <= q)
        {
          topLevel = k;
          break;
        }
      }
      if(topLevel == -1)
      {
        continue;
      }
      l = 1;
      r = topLevel;
      while(r - l > 8)
      {
        int mid = (l + r) / 2;
        if((current | mid) >= p)
        {
          r = mid;
        }
        else
        {
          l = mid;
        }
      }
      int downLevel = -1;
      for(int k = l; k <= r; k++)
      {
        if((current | k) >= p)
        {
          downLevel = k;
          break;
        }
      }
      //printf("down: %d top: %d\n", downLevel, topLevel);
      if(downLevel != -1)
      {
        answer += (topLevel - downLevel) + 1;
      }
    }
  }
  answer = cnt - answer;
}

bool isBitSet(int value, int index)
{
  return (value & (1 << index)) != 0;
}

int dp[32][32][3][3];

int f(int index, int firstBitOn, bool equalP, bool equalQ)
{
  /*if(firstBitOn - index > 24)
  {
    return 0;
  }*/
  if(index == -1)
  {
    return 1;
  }
  if(dp[index][firstBitOn][(int)equalP][(int)equalQ] != -1)
  {
    return dp[index][firstBitOn][(int)equalP][(int)equalQ];
  }
  int result = 0;
  bool pSet = isBitSet(p, index);
  bool qSet = isBitSet(q, index);
  if(equalP && equalQ)
  {
    if(pSet)
    {
      if(firstBitOn - index + 1 <= 24)
      {
        result += f(index - 1, firstBitOn, equalP, qSet);//1
      }
    }
    else
    {
      result += f(index - 1, firstBitOn - (firstBitOn == index ? 1 : 0), equalP, !qSet);//0
      if(qSet == true && (firstBitOn - index + 1 <= 24))
      {
        result += f(index - 1, firstBitOn, false, true);//1
      }
    }
  }
  else if(!equalP && !equalQ)
  {
    result += f(index - 1, firstBitOn - (firstBitOn == index ? 1 : 0), false, false);//0
    if(firstBitOn - index + 1 <= 24)
    {
      result += f(index - 1, firstBitOn, false, false);//1
    }
  }
  else if(equalP)
  {
    if(pSet)
    {
      if(firstBitOn - index + 1 <= 24)
      {
        result += f(index - 1, firstBitOn, equalP, false);//1
      }
    }
    else
    {
      result += f(index - 1, firstBitOn - (firstBitOn == index ? 1 : 0), true, false);//0
      if(firstBitOn - index + 1 <= 24)
      {
        result += f(index - 1, firstBitOn, false, false);//1
      }
    }
  }
  else if(equalQ)
  {
    result += f(index - 1, firstBitOn - (firstBitOn == index ? 1 : 0), equalP, !qSet);//0
    if(qSet == true && (firstBitOn - index + 1 <= 24))
    {
      result += f(index - 1, firstBitOn, false, qSet);//1
    }
  }
  dp[index][firstBitOn][(int)equalP][(int)equalQ] = result;
  return result;
}

void Solve_fast()
{
  int start = -1;
  int copy = q;
  while(copy != 0)
  {
    start++;
    copy >>= 1;
  }
  memset(dp, -1, sizeof(dp));
  answer = f(start, start, true, true);
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
    //time_t t1 = clock();
    ReadData();
    //Solve();
    Solve_fast();
    WriteData();
    //printf("Test %d: %.15f seconds\n", T + 1, (float)(clock() - t1) / CLOCKS_PER_SEC);
  }
  return 0;
}
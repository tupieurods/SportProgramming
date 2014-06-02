#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

char str[20];
int numMasks[10];
bool used[20];
int len;
int m;

void ReadData()
{
  scanf("%s%*c", str);
  scanf("%d%*c", &m);
  len = strlen(str);
}

__int64 answer;
__int64 dp[1<<19][109];

int CntBitsOn(int value)
{
  int result = 0;
  while(value != 0)
  {
    if((value & 1) != 0)
    {
      result++;
    }
    value >>= 1;
  }
  return result;
}

int FirstBitOn(int value)
{
  if(value == 0)
  {
    return 0;
  }
  int result = 0;
  while((value & 1) == 0)
  {
    value >>= 1;
    result++;
  }
  return result;
}

void Solve()
{
  memset(numMasks, 0, sizeof(numMasks));
  for(int i = 0; i < len; i++)
  {
    numMasks[(int)(str[i] - '0')] |= 1 << i;
  }
  answer = 0;
  memset(dp, 0, sizeof(dp));
  for(int mask = 1; mask < (1 << len); mask++)
  {
    if(CntBitsOn(mask) == 1)
    {
      int numIndex = FirstBitOn(mask);
      if(str[numIndex] != '0')
      {
        dp[mask][(int)(str[numIndex] - '0') % m] = 1;
      }
    }
    else
    {
      for(int num = 0; num < 10; num++)
      {
        int workingMask = mask & numMasks[num];
        if(workingMask == 0)
        {
          continue;
        }
        int prevMask = mask & ~(1 << FirstBitOn(workingMask));
        for(int prevMod = 0; prevMod < m; prevMod++)
        {
          int newMod = (prevMod * 10 + num) % m;
          dp[mask][newMod] += dp[prevMask][prevMod];
        }
      }
    }
  }
  answer = dp[(1 << len) - 1][0];
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
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
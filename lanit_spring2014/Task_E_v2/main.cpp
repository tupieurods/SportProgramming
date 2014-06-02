#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <time.h>

using namespace std;

int a[3126];
int n, m, blocksCnt;
char str[100009];

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s%*c", str);
  memset(a, 0, sizeof(a));
  blocksCnt = n / 32 + (n % 32 == 0 ? 0 : 1);
  for(int i = 0, block = 0, bit = 0; i < n; i++)
  {
    if(str[i] == '1')
    {
      a[block] |= 1 << bit;
    }
    bit++;
    if(bit == 32)
    {
      block++;
      bit = 0;
    }
  }
  scanf("%d%*c", &m);
}

int realMasks[35];
int realSS[35][35];

void update(int l, int r, int k)
{
  if(k >= 32)
  {
    for(int i = l; i <= r; i += k)
    {
      a[i / 32] ^= 1 << (i - (i / 32) * 32);
    }
    return;
  }
  int blockStart = l / 32, blockFinish = r / 32;
  l = l - 32 * blockStart;
  r = r - 32 * blockFinish;
  if(blockStart == blockFinish)
  {
    for(int i = l; i <= r; i += k)
    {
      a[blockStart] ^= 1 << i;
    }
    return;
  }
  int realMask = k < 32 ? realMasks[k] : 1;
  int leap = l;
  for(int i = blockStart; i <= blockFinish; i++)
  {
    int mask = realMask << leap;
    if(i == blockFinish)
    {
      mask = mask & (int)((1LL << (r + 1)) - 1);
    }
    a[i] ^= mask;
    leap = realSS[k][leap];
  }
}

void Solve()
{
  for(int T = 1; T < 32; T++)
  {
    realMasks[T] = 0;
    for(int i = 0; i < 32; i += T)
    {
      realMasks[T] |= 1 << i;
    }
    for(int i = 0; i <= 32; i++)
    {
      int mask = realMasks[T] << i;
      realSS[T][i] = 0;
      if(mask != 0)
      {
        int maxOn = 31;
        while(((1 << maxOn) & mask) == 0)
        {
          maxOn--;
        }
        realSS[T][i] = T - (32 - maxOn);
      }
    }
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%s%*c", str);
    if(str[0] == 'o')
    {
      int cnt = n;
      for(int j = 0; j < blocksCnt; j++)
      {
        int bit = 0, copy = a[j];
        while(bit != 32 && cnt != 0)
        {
          bit++;
          cnt--;
          printf("%d", copy & 1);
          copy >>= 1;
        }
      }
      printf("\n");
    }
    else
    {
      int idx = 0;
      int len = strlen(str);
      int l = 0, r = 0, k = 0;
      for(int j = 0; j < len; j++)
      {
        l = l * 10 + (int)(str[j] - '0');
      }
      scanf("%d %d%*c", &r, &k);
      l--;
      r--;
      update(l, r, k);
    }
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    //clock_t tim = clock();
    ReadData();
    Solve();
    WriteData();
    //fprintf(stderr, "%.5f\n", ((float)((clock() - tim)) / CLOCKS_PER_SEC));
  }
  return 0;
}
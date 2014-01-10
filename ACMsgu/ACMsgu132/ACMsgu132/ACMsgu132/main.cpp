#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

struct element
{
  int added, mask, downMask;
};

int n, m;
unsigned char answer;
int* lines;

void ReadData()
{
  scanf("%d %d", &m, &n);
  lines = new int[m + 1];
  for(int i = 0; i < m; i++)
  {
    scanf("\n");
    lines[i] = 0;
    for(int j = 0; j < n; j++)
    {
      char c;
      scanf("%c", &c);
      if(c == '*')
        lines[i] |= 1 << j;
    }
  }
  lines[m] = (1 << n) - 1;
}

bool maskValidateChache[128];

void validate1(int mask)
{
  for(int i = 0; i < n - 1; i++)
  {
    if((mask & (3 << i)) == 0)
    {
      maskValidateChache[mask] = false;
      return;
    }
  }
  maskValidateChache[mask] = true;
}

inline bool validate(int mask)
{
  return maskValidateChache[mask];
}

bool MoreCacheMore[128][128];

void columnsValidate1(int prevMask, int currentMask)
{
  for(int i = 0; i < n; i++)
  {
    if(((prevMask & (1 << i)) == 0) && ((currentMask & (1 << i)) == 0))
    {
      MoreCacheMore[prevMask][currentMask] = false;
      return;
    }
  }
  MoreCacheMore[prevMask][currentMask] = true;
}

inline bool columnsValidate(int prevMask, int currentMask)
{
  return MoreCacheMore[prevMask][currentMask];
}

void gen(int str, int prevMask, int mask, int downMask, int added, int pos, vector<element> &downMasks)
{
  if(pos == n)
  {
    bool rowFlag = validate(mask);
    bool columnsFlag = columnsValidate(prevMask, mask);
    if(rowFlag && columnsFlag)
    {
      element elem;
      elem.added = added;
      elem.downMask = downMask;
      elem.mask = mask;
      downMasks.push_back(elem);
    }
    return;
  }
  if((mask & (1 << pos)) == 0)
  {
    if((downMask & (1 << pos)) == 0)
      gen(str, prevMask, mask | (1 << pos), downMask | (1 << pos), added + 1, pos + 1, downMasks);
    if((pos + 1 != n) && ((mask & (1 << (pos + 1))) == 0))
      gen(str, prevMask, mask | (3 << pos), downMask, added + 1, pos + 1, downMasks);
  }
  gen(str, prevMask, mask, downMask, added, pos + 1, downMasks);
}

unsigned char min(unsigned char v1, unsigned char v2)
{
  return v1 < v2 ? v1 : v2;
}

unsigned char Sum(unsigned char v1, unsigned char v2)
{
  if(v1 == 0xFF || v2 == 0xFF)
    return 0xFF;
  return v1 + v2;
}

unsigned char dp[70][128][128];

unsigned char f(int str, int mask, int prevMask)
{
  if(str == m)
    return (unsigned char)0;
  if(dp[str][mask][prevMask] != 0xFF)
    return dp[str][mask][prevMask];
  unsigned char result = 0xFF;
  vector<element> masks;
  gen(str, prevMask, mask, lines[str + 1], 0, 0, masks);
  for(vector<element>::iterator it = masks.begin(); it != masks.end(); it++)
  {
    result = min(result, Sum(it->added, f(str + 1, it->downMask, it->mask)));
  }
  dp[str][mask][prevMask] = result;
  return result;
}

void Solve()
{
  for(int i = 0; i < 128; i++)
  {
    validate1(i);
    for(int j = 0; j < 128; j++)
    {
      columnsValidate1(i, j);
    }
  }
  memset(dp, 0xFF, sizeof(dp));
  //[Маска][Маска из которой мы пришли в маску из первого индекса]
  /*int currentLine[128][128], nextLine[128][128];
  memset(currentLine, 0xFF, sizeof(currentLine));
  currentLine[lines[0]][(1 << n) - 1] = 0;
  for(int lineNumber = 0; lineNumber < m; lineNumber++)
  {
    memset(nextLine, 0xFF, sizeof(nextLine));
    for(int currentMask = 0; currentMask < (1 << n); currentMask++)
    {
      for(int prevMask = 0; prevMask < (1 << n); prevMask++)
      {
        if(currentLine[currentMask][prevMask] != -1)
        {
          vector<element> masks;
          gen(lineNumber, prevMask, currentMask, lines[lineNumber + 1], 0, 0, masks);
          for(vector<element>::iterator it = masks.begin(); it != masks.end(); it++)
          {
            if(nextLine[it->downMask][it->mask] == -1
              || currentLine[currentMask][prevMask] + it->added < nextLine[it->downMask][it->mask])
            {
              nextLine[it->downMask][it->mask] = currentLine[currentMask][prevMask] + it->added;
            }
          }
        }
      }
    }
    swap(currentLine, nextLine);
  }
  answer = INT_MAX;
  for(int prevMask = 0; prevMask < 128; prevMask++)
  {
    if(currentLine[(1 << n) - 1][prevMask] != -1)
    {
      answer = min(answer, currentLine[(1 << n) - 1][prevMask]);
    }
  }*/
  answer = f(0, lines[0], 127);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n70 7\n");
    for(int i = 0; i < 70; i++)
    {
      printf(".......\n");
    }
  }
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
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
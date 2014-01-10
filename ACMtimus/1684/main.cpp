#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char str1[160000];
char str2[75005];
int len, len1, totalLen;
int spaceCount;
int answer[75005];
bool flag;
int z[75005];

inline int min(int a, int b)
{
  return a < b ? a : b;
}

void CalcZ()
{
  int l = -1, r = -1;
  for(int i = len1 + 1; i < totalLen; i++)
  {
    int rPos = i - (len1 + 1);
    if(i <= r)
    {
      z[rPos] = min(r - i + 1, z[i - 2 * rPos - l]);
    }
    while(z[rPos] + i < totalLen
      && str1[z[rPos]] == str1[z[rPos] + i])
    {
      z[rPos]++;
    }
    if(z[rPos] + i - 1 > r)
    {
      l = i;
      r = z[rPos] + rPos - 1;
    }
  }
}

void ReadData()
{
  scanf("%s\n", &str1);
  scanf("%s\n", &str2);
  len = strlen(str2);
  len1 = strlen(str1);
  /*if(len > 75000 || len1 > 75000)
  {
    throw;
  }*/
  totalLen = len + len1 + 1;
  str1[len1] = '#';
  str1[len1 + 1] = '\0';
  strcat(str1, str2);
}

void Solve()
{
  CalcZ();
  int pos = totalLen - 1;
  int current = totalLen;
  int added = 0;
  spaceCount = 0;
  while(pos != len1)
  {
    int rPos = pos - (len1 + 1);
    if((z[rPos] > 0)
        && ((current - pos) <= z[rPos]))
    {
      added += current - pos;
      answer[spaceCount] = rPos + current - pos - 1;
      spaceCount++;
      current = pos;
    }
    pos--;
  }
  flag = (added == len);
}

void WriteData()
{
  if(flag)
  {
    printf("No\n");
    int current = spaceCount - 1;
    for(int i = 0; i < len; i++)
    {
      putchar(str2[i]);
      if(current != -1 && i == answer[current])
      {
        putchar(' ');
        current--;
      }
    }
  }
  else
  {
    printf("Yes\n");
  }
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d\n", &QWE);
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
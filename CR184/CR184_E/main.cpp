#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

char str[5009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

int answer;
int answerStep;
//could be solved without it, just algo practice
int pal[5009];
vector<pair<int, int>> globNim;
int grandi[5009];

int calcPos(int srcLen, int checker)
{
  for(int i = 0; i < srcLen; i++)
  {
    int l = max(i - 1, 0), r = max(srcLen - i - 2, 0);
    if((grandi[l] ^ grandi[r]) == checker)
    {
      return i;
    }
  }
  return -1;
}

void Solve()
{
  answer = 0;
  answerStep = -1;
  memset(pal, 0, sizeof(pal));
  for(int i = 0; i < len; i++)
  {
    pal[i] = 1;
    while(((i - pal[i]) >= 0) && ((i + pal[i]) < len) && str[i - pal[i]] == str[i + pal[i]])
    {
      pal[i]++;
    }
  }
  //printf("stage1 done\n");
  globNim.clear();
  for(int i = 0; i < len; i++)
  {
    int current = 0, startPos = i;
    while(i < len && pal[i] > 1)
    {
      current++;
      i++;
    }
    if(current != 0)
    {
      i--;
      globNim.push_back(make_pair(startPos, current));
      answer ^= current <= 0 ? 0 : grandi[current];
    }
  }
  if(answer != 0)
  {
    for(vector<pair<int, int>>::iterator it = globNim.begin(); it != globNim.end(); it++)
    {
      answerStep = calcPos(it->second, answer ^ grandi[it->second]);
      if(answerStep != -1)
      {
        answerStep += it->first + 1;
        break;
      }
    }
  }
}

void WriteData()
{
  if(answer != 0)
  {
    printf("First\n%d\n", answerStep);
  }
  else
  {
    printf("Second\n");
  }
}

int main()
{
  memset(grandi, 0, sizeof(grandi));
  int used[10000];
  memset(used, 0, sizeof(used));
  for(int currLen = 1; currLen < 5001; currLen++)
  {
    for(int i = 0; i < currLen; i++)
    {
      int l = max(i - 1, 0), r = max(currLen - i - 2, 0);
      used[grandi[l] ^ grandi[r]] = currLen;
    }
    for(int i = 0; i < 10000; i++)
    {
      if(used[i] != currLen)
      {
        grandi[currLen] = i;
        break;
      }
    }
  }
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
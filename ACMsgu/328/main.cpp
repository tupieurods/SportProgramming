#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int n;
char str[100009];
int grandi[6][100009];

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s%*c", str);
}

inline int getIdx(int l, int r)
{
  int code = min(l, r) * 10 + max(l, r);
  switch(code)
  {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 11: return 3;
    case 22: return 4;
    case 12: return 5;
  }
  return -1;
}

bool answer;

void Solve()
{
  int answerVal = 0;
  int l = 0, r = 0;
  int len = 0;
  for(int i = 0; i < n; i++)
  {
    if(str[i] != '0')
    {
      if(len != 0)
      {
        answerVal ^= grandi[getIdx(l, (int)(str[i] - '0'))][len];
        len = 0;
      }
      l = (int)(str[i] - '0');
    }
    else
    {
      len++;
    }
  }
  if(len != 0)
  {
    answerVal ^= grandi[getIdx(l, 0)][len];
  }
  answer = answerVal != 0;
}

void WriteData()
{
  if(answer)
  {
    printf("FIRST\n");
  }
  else
  {
    printf("SECOND\n");
  }
}

int conf[6][2] = 
{
  {0, 0},
  {0, 1},
  {0, 2},
  {1, 1},
  {2, 2},
  {1, 2},
};

int main()
{
  //grandi precalc
  memset(grandi, 0, sizeof(grandi));
  for(int i = 0; i < 5; i++)
  {
    grandi[i][1] = 1;
  }
  for(int i = 2; i < 100009; i++)
  {
    grandi[0][i] = i % 2;
  }
  for(int T = 1; T < 3; T++)
  {
    for(int i = 2; i < 100009; i++)
    {
      grandi[T][i] = i;
    }
  }
  for(int T = 3; T < 5; T++)
  {
    for(int i = 2; i < 100009; i++)
    {
      grandi[T][i] = 1;
    }
  }
  /*
  freopen("test.txt", "w", stdout);
  int used[200009];
  memset(used, 0, sizeof(used));
  int current = 0;
  for(int len = 2; len < 309; len++)
  {
    for(int i = 0; i < 6; i++)
    {
      current++;
      for(int j = 0; j < 2; j++)
      {
        switch(conf[i][j])
        {
          case 0:
          {
            used[grandi[getIdx(1, conf[i][1 ^ j])][len - 1]] = current;
            used[grandi[getIdx(2, conf[i][1 ^ j])][len - 1]] = current;
            break;
          }
          case 1:
          {
            used[grandi[getIdx(2, conf[i][1 ^ j])][len - 1]] = current;
            break;
          }
          case 2:
          {
            used[grandi[getIdx(1, conf[i][1 ^ j])][len - 1]] = current;
            break;
          }
        }
      }
      for(int j = 2; j < len; j++)
      {
        int r = grandi[getIdx(conf[i][0], 1)][j - 1] ^ grandi[getIdx(1, conf[i][1])][len - j];
        used[r] = current;
        r = grandi[getIdx(conf[i][0], 2)][j - 1] ^ grandi[getIdx(2, conf[i][1])][len - j];
        used[r] = current;
      }
      for(int j = 0; j < 200009; j++)
      {
        if(used[j] != current)
        {
          grandi[i][len] = j;
          break;
        }
      }
    }
  }
  for(int i = 0; i < 6; i++)
  {
    for(int j = 0; j < 309; j++)
    {
      printf("%d ", grandi[i][j]);
    }
    printf("\n");
  }
  printf("finished\n");
  return 0;*/
  //grandi precalc
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
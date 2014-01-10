#include <string>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct data
{
  int value[2];
};

#define TWO 0
#define FIVE 1

data **inTable;
data **next;
string anwser;
int flag;
int **cache;
int n;
int result;

void ClearCache()
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cache[i][j] = -1;
}

int inline min(int x, int y)
{
  return x > y ? y : x;
}

int f(int x, int y, int flag)
{
  if(x == 0 && y == 0)
    return inTable[0][0].value[flag];
  if(cache[x][y] == -1)
    {
      int first = x == 0 ? INT_MAX : f(x - 1, y, flag);
      int second = y == 0 ? INT_MAX : f(x, y - 1, flag);
      if(first < second)
        {
          cache[x][y] = first + inTable[x][y].value[flag];
          next[x][y].value[flag] = 1;
        }
      else
        {
          cache[x][y] = second + inTable[x][y].value[flag];
          next[x][y].value[flag] = 2;
        }
    }
  return cache[x][y];
}

int main()
{
  scanf("%d", &n);
  inTable = new data*[n];
  next = new data*[n];
  cache = new int*[n];
  int ZeroX=-1;
  int ZeroY=-1;
  for(int i = 0; i < n; i++)
    {
      inTable[i] = new data[n];
      next[i] = new data[n];
      cache[i] = new int[n];
      for(int j = 0; j < n; j++)
        {
          next[i][j].value[TWO] = 0;
          next[i][j].value[FIVE] = 0;
          cache[i][j] = -1;
          int tmp;
          scanf("%d", &tmp);
          if(tmp == 0)
          {
            tmp = 10;
            ZeroX=j;
            ZeroY=i;
          }
          int calc = 0;
          while(tmp % 2 == 0)
            {
              calc++;
              tmp /= 2;
            }
          inTable[i][j].value[TWO] = calc;
          calc = 0;
          while(tmp % 5 == 0)
            {
              calc++;
              tmp /= 5;
            }
          inTable[i][j].value[FIVE] = calc;
        }
    }
  int res1 = f(n - 1, n - 1, TWO);
  ClearCache();
  int res2 = f(n - 1, n - 1, FIVE);
  result = min(res1, res2);
  if(ZeroX!=-1 && result>1)
  {
    printf("1\n");
    int x=0;
    int y=0;
    while(x!=ZeroX)
    {
      printf("R");
      x++;
    }
    while(y!=ZeroY)
    {
      printf("D");
      y++;
    }
    while(x!=n-1)
    {
      printf("R");
      x++;
    }
    while(y!=n-1)
    {
      printf("D");
      y++;
    }
    return 0;
  }
  printf("%d\n", result);
  anwser = "";
  int x = n - 1;
  int y = n - 1;
  flag = res1 > res2 ? FIVE : TWO;
  do
    {
      if(next[x][y].value[flag] == 1)
        {
          anwser += "D";
          x--;
        }
      else
        {
          anwser += "R";
          y--;
        }
    }
  while(x != 0 || y != 0);
  reverse(anwser.begin(),anwser.end());
  printf("%s", anwser.c_str());
  return 0;
}

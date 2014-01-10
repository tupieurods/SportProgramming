#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
char table[1009][1009];

void ReadData()
{
  scanf("%d %d%*c", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", table[i]);
  }
}

int cache[1009][1009];
int color[1009][1009];

int dfsVisit(int xpos, int ypos);

int dfs()
{
  int result = 0;
  memset(cache, 0xFF, sizeof(cache));
  memset(color, 0, sizeof(color));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(table[i][j] == 'D' && color[i][j] == 0)
      {
        int current = dfsVisit(j, i);
        if(current == INT_MAX)
        {
          return current;
        }
        result = max(result, current);
      }
    }
  }
  return result;
}

int moves[4][2] = 
{
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

char getNext(char c)
{
  switch(c)
  {
    case 'D':
      return 'I';
    case 'I':
      return 'M';
    case 'M':
      return 'A';
    case 'A':
      return 'D';
    default:
      throw;
  };
  return '\0';
}

bool valid(int xpos, int ypos, char c)
{
  if(xpos < 0 || ypos < 0 || xpos >= m || ypos >= n || table[ypos][xpos] != c)
  {
    return false;
  }
  return true;
}

int dfsVisit(int xpos, int ypos)
{
  if(color[ypos][xpos] == 1)
  {
    return INT_MAX;
  }
  if(color[ypos][xpos] == 2)
  {
    return cache[ypos][xpos];
  }
  color[ypos][xpos] = 1;
  int result = 0;
  for(int i = 0; i < 4; i++)
  {
    if(valid(xpos + moves[i][0], ypos + moves[i][1], getNext(table[ypos][xpos])))
    {
      int current = dfsVisit(xpos + moves[i][0], ypos + moves[i][1]);
      if(current == INT_MAX)
      {
        color[ypos][xpos] = 2;
        cache[ypos][xpos] = INT_MAX;
        return INT_MAX;
      }
      result = max(result, current);
    }
  }
  if(table[ypos][xpos] == 'A')
  {
    result++;
  }
  color[ypos][xpos] = 2;
  cache[ypos][xpos] = result;
  return result;
}

int answer;

void Solve()
{
  answer = dfs();
}

void WriteData()
{
  if(answer == 0)
  {
    printf("Poor Dima!\n");
  }
  else if(answer == INT_MAX)
  {
    printf("Poor Inna!\n");
  }
  else
  {
    printf("%d\n", answer);
  }
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
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int h, w, c;
int q[12];
int matrix[12][10][10];

void ReadData()
{
  scanf("%d %d %d", &h, &w, &c);
  q[0] = 0;
  for(int i = 0; i < c; i++)
  {
    scanf("%d", &q[i + 1]);
  }
  for(int row = 0; row < h; row++)
  {
    for(int column = 0; column < w; column++)
    {
      scanf("%d", &matrix[0][row][column]);
    }
  }
}

int moves[4][2] = 
{
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1}
};

int counts[12][12];
int used[12];
int tmpMatrix[10][10];
int NumberingUsed;

inline bool checkInside(int yval, int xval)
{
  return xval >= 0 && yval >= 0 && xval < w && yval < h;
}

void bfs(int row, int column, int current, int step)
{
  queue<pair<int, int>> q;
  q.push(make_pair(row, column));

  while(!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop();

    for(int moveId = 0; moveId < 4; moveId++)
    {
      int newY = curr.first + moves[moveId][0];
      int newX = curr.second + moves[moveId][1];
      if(checkInside(newY, newX) && (matrix[step][newY][newX] == current) && tmpMatrix[newY][newX] != NumberingUsed)
      {
        tmpMatrix[newY][newX] = NumberingUsed;
        q.push(make_pair(newY, newX));
      }
    }
  }
}

bool f(int step)
{
  NumberingUsed++;
  if(step + 1 == c)
  {
    return true;
  }
  memset(counts[step], 0, sizeof(counts[step]));
  for(int row = 0; row < h; row++)
  {
    for(int column = 0; column < w; column++)
    {
      if(matrix[step][row][column] == 0)
      {
        continue;
      }
      int current = matrix[step][row][column];
      if(used[current] != NumberingUsed)
      {
        used[current] = NumberingUsed;
        tmpMatrix[row][column] = NumberingUsed;
        bfs(row, column, current, step);
      }
    }
  }
  for(int row = 0; row < h; row++)
  {
    for(int column = 0; column < w; column++)
    {
      if(tmpMatrix[row][column] == NumberingUsed)
      {
        counts[step][matrix[step][row][column]]++;
      }
    }
  }
  for(int i = 1; i <= c; i++)
  {
    if(counts[step][i] != q[i])
    {
      continue;
    }
    memset(matrix[step + 1], 0, sizeof(matrix[step + 1]));
    int realColumn = 0;
    for(int column = 0; column < w; column++)
    {
      int realRow = h - 1;
      for(int row = h - 1; row >= 0; row--)
      {
        if(matrix[step][row][column] != i)
        {
          matrix[step + 1][realRow][realColumn] = matrix[step][row][column];
          realRow--;
        }
      }
      if(realRow != h - 1)
      {
        realColumn++;
      }
    }
    if(f(step + 1))
    {
      return true;
    }
  }
  return false;
}

bool answer;

void Solve()
{
  memset(tmpMatrix, 0, sizeof(tmpMatrix));
  memset(used, 0, sizeof(used));
  NumberingUsed = 0;
  answer = f(0);
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
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
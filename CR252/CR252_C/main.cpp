#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

int n, m, k;

bool matrix[309][309];

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
}

vector<pair<int, int>> answer[90009];

void fillMatrix(int row, int col, int total, int dir, int cdir, int top, int bot)
{
  while(total != 0)
  {
    if(matrix[row][col] == false)
    {
      matrix[row][col] = true;
      answer[0].push_back(make_pair(row, col));
      total--;
    }
    switch(dir)
    {
      case 0://down
      {
        if(row != bot && matrix[row + 1][col] == false)
        {
          row++;
        }
        else
        {
          dir = cdir;
        }
        break;
      }
      case 1://up
      {
        if(row != top && matrix[row - 1][col] == false)
        {
          row--;
        }
        else
        {
          dir = cdir;
        }
        break;
      }
      case 2://left
      {
        if(col != 0 && matrix[row][col - 1] == false)
        {
          col--;
        }
        dir = row == bot ? 1 : 0;
        break;
      }
      case 3://right
      {
        if(col != m - 1 && matrix[row][col + 1] == false)
        {
          col++;
        }
        dir = row == bot ? 1 : 0;
        break;
      }
    }
  }
}

void Solve()
{
#ifndef ONLINE_JUDGE
  for(int i = 0; i < k; i++)
  {
    answer[i].clear();
  }
#endif
  memset(matrix, 0, sizeof(matrix));
  int fullTotal = n * m;
  int row = 0, col = 0;
  int stage = 0;
  for(int i = 1; i < k; i++)
  {
    if(stage == 0)
    {
      if(col + 2 > m)
      {
        col = 0;
        row++;
        if(row == n)
        {
          row = 0;
          col = m - 1;
          i--;
          stage = 2;
          continue;
        }
      }
      answer[i].push_back(make_pair(row, col));
      answer[i].push_back(make_pair(row, col + 1));
      fullTotal -= 2;
      matrix[row][col] = true;
      matrix[row][col + 1] = true;
      col += 2;
    }
    if(stage == 2)
    {
      answer[i].push_back(make_pair(row, col));
      answer[i].push_back(make_pair(row + 1, col));
      fullTotal -= 2;
      matrix[row][col] = true;
      matrix[row + 1][col] = true;
      row += 2;
    }
  }
  if(col == 0 || ((m - col) % 2) == 1 || row == n - 1)
  {
    if(!matrix[0][m - 1])
    {
      row = 0;
    }
    //int total = n * m - 2 * (k - 1);
    int dir = 0;
    col = m - 1;
    fillMatrix(row, col, fullTotal, dir, 2, 0, n - 1);
  }
  else
  {
    int total = 2 * m - col;
    fillMatrix(row + 1, 0, total, 3, 3, 0, row + 1);
    //printf("fail");
    if(total != fullTotal)
    {
      fillMatrix(row + 2, m - 1, fullTotal - total, 0, 2, 0, n - 1);
    }
  }
}

void WriteData()
{
  for(int i = 0; i < k; i++)
  {
    printf("%d ", answer[i].size());
    for(vector<pair<int, int>>::iterator it = answer[i].begin(); it != answer[i].end(); ++it)
    {
      printf("%d %d ", it->first + 1, it->second + 1);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
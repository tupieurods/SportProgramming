#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
char answer[109][109];
char overflow;

void ReadData()
{
  for(int i = 0; i < 109; i++)
  {
    for(int j = 0; j < 109; j++)
    {
      answer[i][j] = '.';
    }
  }
  scanf("%d %d", &n, &m);
}

char getSymbol(int row, int column)
{
  if(row < 0 || column < 0 || row >= n || column >= m
    || answer[row][column] == '.')
  {
    return overflow;
  }
  return answer[row][column];
}

char getMinimal(char c1, char c2, char c3)
{
  for(char result = 'A'; result < overflow; result++)
  {
    if(result != c1 && result != c2 && result != c3)
    {
      return result;
    }
  }
  throw;
  //return overflow;
}

bool check(int row, int column, int sz, char current)
{
  sz--;
  //Inside table
  if(row + sz >= n || column + sz >= m)
  {
    return false;
  }
  //Check upperRight corner
  char checker = getMinimal(overflow, getSymbol(row - 1, column + sz), getSymbol(row, column + sz + 1));
  if(checker < current)
  {
    return false;
  }
  for(int i = row; i <= row + sz; i++)
  {
    if(answer[i][column] != '.' || getSymbol(i, column - 1) == current)
    {
      return false;
    }
    if(answer[i][column + sz] != '.' || getSymbol(i, column + sz + 1) == current)
    {
      return false;
    }
  }
  for(int i = column; i <= column + sz; i++)
  {
    if(answer[row][i] != '.' || getSymbol(row - 1, i) == current)
    {
      return false;
    }
    if(answer[row + sz][i] != '.')
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  for(int row = 0; row < n; row++)
  {
    for(int column = 0; column < m; column++)
    {
      if(answer[row][column] != '.')
      {
        continue;
      }
      char current = getMinimal(getSymbol(row - 1, column), getSymbol(row, column - 1), getSymbol(row, column + 1));
      int sz = 2;
      while(check(row, column, sz, current))
      {
        sz++;
      }
      sz--;
      for(int i = 0; i < sz; i++)
      {
        for(int j = 0; j < sz; j++)
        {
          answer[row + i][column + j] = current;
        }
      }
    }
  }
}

void WriteData()
{
  for(int row = 0; row < n; row++)
  {
    for(int column = 0; column < m; column++)
    {
      printf("%c", answer[row][column]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  overflow = 'Z' + 1;
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
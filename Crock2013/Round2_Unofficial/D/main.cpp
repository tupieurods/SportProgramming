#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
int n, m, k;
int **matrix;
int answer;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  matrix = new int*[n];
  for(int i = 0; i < n; i++)
  {
    matrix[i] = new int[m];
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int f(int line, int column)
{
  if(column >= m)
  {
    return f(line + 1, 0);
  }
  bool bad[11], good[11];
  memset(bad, 0, sizeof(bad));
  memset(good, 0, sizeof(good));
  //Подсчёт ответа
  if(line >= n)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        good[matrix[i][j]] = true;
        //printf("%d ", matrix[i][j]);
      }
      //printf("\n");
    }
    int cnt = 0;
    for(int i = 1; i <= k; i++)
    {
      if(good[i])
      {
        cnt++;
      }
    }
    //printf("cnt: %d\n", cnt);
    int top = 1, down = 1;
    for(int i = 2; i <= k; i++)
    {
      top *= i;
      if(i <= k - cnt)
      {
        down *= i;
      }
    }
    return (top / down) % mod;
  }
  //Цвета которые нельзя использовать
  int maximal = 0;
  for(int i = 0; i <= line; i++)
  {
    for(int j = 0; j <= column; j++)
    {
      if(line == i && column == j)
      {
        continue;
      }
      bad[matrix[i][j]] = true;
      maximal = max(maximal, matrix[i][j]);
    }
  }
  for(int i = line; i < n; i++)
  {
    for(int j = column; j < m; j++)
    {
      if(line == i && column == j)
      {
        continue;
      }
      bad[matrix[i][j]] = true;
    }
  }
  //Цвета которые можно использовать
  for(int i = 0; i < line; i++)
  {
    for(int j = column; j < m; j++)
    {
      if(line == i && column == j)
      {
        continue;
      }
      good[matrix[i][j]] = true;
      maximal = max(maximal, matrix[i][j]);
    }
  }
  //Перебор
  int result = 0;
  maximal++;
  while(maximal <= k && bad[maximal])
    maximal++;
  if(matrix[line][column] == 0)
  {
    int topBound = min(k, maximal);
    for(int color = 1; color <= topBound; color++)
    {
      if((!bad[color] && good[color]) || (color == maximal))
      {
        //printf("line: %d column: %d color: %d\n", line, column, color);
        matrix[line][column] = color;
        result += f(line, column + 1);
        result %= mod;
        matrix[line][column] = 0;
      }
    }
  }
  else
  {
    
  }
  return result % mod;
}

void Solve()
{
  answer = 0;
  if(n + m - 1 > k)
    return;
  answer = f(0, 0) % mod;
}

void WriteData()
{
  printf("%d\n", answer);
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
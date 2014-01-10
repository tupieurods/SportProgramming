#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;

void ReadData()
{
  scanf("%d", &k);
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int answer;
bool matrix[100][100];

void Solve()
{
  answer = 100;
  int cnt = 0;
  memset(matrix, 0, sizeof(matrix));
  for(int i = 1; i < 100; i++)
  {
    matrix[i][0] = true;
    matrix[0][i] = true;
  }
  for(int from = 1; from < 99; from++)
  {
    for(int j = 1; j < from; j++)
    {
      int to = 1 + j;
      if(from == to || matrix[from][to])
        continue;
      //answer = max(answer, to + 1);
      matrix[from][to] = true;
      matrix[to][from] = true;
      int toAdd = 0;
      for(int third = 0; third < answer; third++)
      {
        if(third != from && third != to
          && matrix[from][third] && matrix[third][to])
          toAdd++;
      }
      if(cnt + toAdd > k)
      {
        matrix[from][to] = false;
        matrix[to][from] = false;
      }
      else
      {
        cnt += toAdd;
      }
      if(cnt == k)
        return;
    }
    if(cnt == k)
      return;
  }
  if(cnt != k)
    throw;
    //printf("fail: %d\n", cnt);
}

void WriteData()
{
  printf("%d\n", answer);
  for(int row = 0; row < answer; row++)
  {
    for(int column = 0; column < answer; column++)
    {
      printf("%d", (int)matrix[row][column]);
    }
    printf("\n");
  }
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
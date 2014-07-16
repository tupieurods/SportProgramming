#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, typesNum;
char str[5];
bool matrix[5][5];

int getRow(char c)
{
  switch(c)
  {
    case 'R': return 0;
    case 'G': return 1;
    case 'B': return 2;
    case 'Y': return 3;
    case 'W': return 4;
  }
  return -1;
}

void ReadData()
{
  memset(matrix, 0, sizeof(matrix));
  scanf("%d%*c", &n);
  typesNum = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    int row = getRow(str[0]);
    int column = (str[1] - '0') - 1;
    if(matrix[row][column] == false)
    {
      typesNum++;
    }
    matrix[row][column] = true;
    //printf("%s|\n", str);
  }
}

bool matrix2[5][5];

bool check(int mask)
{
  memcpy(matrix2, matrix, sizeof(matrix));
  int rowData = mask & 31;
  mask >>= 5;
  int tN = typesNum;
  for(int row = 0; row < 5; row++)
  {
    for(int column = 0; column < 5; column++)
    {
      if(matrix2[row][column] 
        && ((rowData & (1 << column)) != 0)
        && ((mask & (1 << row)) != 0))
      {
        tN--;
        matrix2[row][column] = false;
      }
    }
  }
  for(int i = 0; i < 40; i++)
  {
    if(tN <= 1)
    {
      return true;
    }
    for(int row = 0; row < 5; row++)
    {
      if((mask & (1 << row)) == 0)
      {
        continue;
      }
      int cnt = 0;
      int idx = 0;
      for(int column = 0; column < 5; column++)
      {
        if(matrix2[row][column])
        {
          cnt++;
          idx = column;
        }
      }
      if(cnt == 1)
      {
        matrix2[row][idx] = false;
        tN--;
      }
    }
    for(int column = 0; column < 5; column++)
    {
      if((rowData & (1 << column)) == 0)
      {
        continue;
      }
      int cnt = 0;
      int idx = 0;
      for(int row = 0; row < 5; row++)
      {
        if(matrix2[row][column])
        {
          cnt++;
          idx = row;
        }
      }
      if(cnt == 1)
      {
        matrix2[idx][column] = false;
        tN--;
      }
    }
  }
  return false;
}

int answer;

void Solve()
{
  answer = 1000000;
  for(int mask = 0; mask < 1024; mask++)
  {
    /*if(mask == 40)
    {
      printf("!");
    }*/
    if(check(mask))
    {
      int copy = mask;
      int current = 0;
      while(copy != 0)
      {
        if((copy & 1) != 0)
        {
          current++;
        }
        copy >>= 1;
      }
      answer = std::min(current, answer);
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
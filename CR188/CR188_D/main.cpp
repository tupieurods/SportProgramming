//Fast solution at the end of file(156ms instead of 436ms)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

#define MAX_SIZE 65
int n, t;
int field[MAX_SIZE][MAX_SIZE], fieldChanges[MAX_SIZE][MAX_SIZE];

void ReadData()
{
  scanf("%d %d", &n, &t);
}

inline void fix()
{
  memcpy(field, fieldChanges, sizeof(field));
  /*for(int row = 0; row < MAX_SIZE; row++)
  {
  for(int column = 0; column < MAX_SIZE; column++)
  {
  field[row][column] += fieldChanges[row][column];
  fieldChanges[row][column] = 0;
  }
  }*/
}

void Solve()
{
  memset(fieldChanges, 0, sizeof(fieldChanges));
  fieldChanges[0][0] = n;
  fix();
  bool changed = true;
  //int check = 0;
  while(changed)
  {
    //printf("%d\n", field[0][0]);
    changed = false;
    for(int row = 0; row < MAX_SIZE; row++)
    {
      for(int column = 0; column < MAX_SIZE; column++)
      {
        if(field[row][column] < 4)
        {
          continue;
        }
        //check = std::max(check, std::max(row, column));
        changed = true;
        fieldChanges[row][column] -= 4;
        if(row == 0 && column == 0)
        {
          fieldChanges[row + 1][column]++;
          fieldChanges[row][column + 1]++;
        }
        else if(row == 0 || column == 0)
        {
          fieldChanges[row + 1][column]++;
          fieldChanges[row][column + 1]++;
          if(column == 0)
          {
            fieldChanges[row - 1][column] += row == 1 ? 2 : 1;
          }
          else if(row == 0)
          {
            fieldChanges[row][column - 1] += column == 1 ? 2 : 1;
          }
        }
        else
        {
          fieldChanges[row + 1][column]++;
          fieldChanges[row][column + 1]++;
          fieldChanges[row - 1][column] += row == 1 ? 2 : 1;
          fieldChanges[row][column - 1] += column == 1 ? 2 : 1;
        }
      }
    }
    fix();
  }
  //printf("%d\n", check);
}

void WriteData()
{
  for(int i = 0; i < t; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    x = abs(x);
    y = abs(y);
    if(x >= MAX_SIZE || y >= MAX_SIZE)
    {
      printf("0\n");
    }
    else
    {
      printf("%d\n", field[y][x]);
    }
  }
  printf("\n");
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

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <algorithm>
//
//#pragma warning(disable: 4996)
//
//#define MAX_SIZE 65
//int n, t;
//int field[MAX_SIZE][MAX_SIZE], fieldChanges[MAX_SIZE][MAX_SIZE];
//
//void ReadData()
//{
//  scanf("%d %d", &n, &t);
//}
//
//inline void fix()
//{
//  memcpy(field, fieldChanges, sizeof(field));
//  /*for(int row = 0; row < MAX_SIZE; row++)
//  {
//    for(int column = 0; column < MAX_SIZE; column++)
//    {
//      field[row][column] += fieldChanges[row][column];
//      fieldChanges[row][column] = 0;
//    }
//  }*/
//}
//
//void Solve()
//{
//  memset(fieldChanges, 0, sizeof(fieldChanges));
//  fieldChanges[0][0] = n;
//  fix();
//  bool changed = true;
//  //int check = 0;
//  while(changed)
//  {
//    //printf("%d\n", field[0][0]);
//    changed = false;
//    for(int row = 0; row < MAX_SIZE; row++)
//    {
//      for(int column = 0; column < MAX_SIZE; column++)
//      {
//        if(field[row][column] < 4)
//        {
//          continue;
//        }
//        //check = std::max(check, std::max(row, column));
//        changed = true;
//        int mul = fieldChanges[row][column] / 4;
//        fieldChanges[row][column] %= 4;
//        if(row == 0 && column == 0)
//        {
//          fieldChanges[row + 1][column] += mul;
//          fieldChanges[row][column + 1] += mul;
//        }
//        else if(row == 0 || column == 0)
//        {
//          fieldChanges[row + 1][column] += mul;
//          fieldChanges[row][column + 1] += mul;
//          if(column == 0)
//          {
//            fieldChanges[row - 1][column] += row == 1 ? 2 * mul : mul;
//          }
//          else if(row == 0)
//          {
//            fieldChanges[row][column - 1] += column == 1 ? 2 * mul : mul;
//          }
//        }
//        else
//        {
//          fieldChanges[row + 1][column] += mul;
//          fieldChanges[row][column + 1] += mul;
//          fieldChanges[row - 1][column] += row == 1 ? 2 * mul : mul;
//          fieldChanges[row][column - 1] += column == 1 ? 2 * mul : mul;
//        }
//      }
//    }
//    fix();
//  }
//  //printf("%d\n", check);
//}
//
//void WriteData()
//{
//  for(int i = 0; i < t; i++)
//  {
//    int x, y;
//    scanf("%d %d", &x, &y);
//    x = abs(x);
//    y = abs(y);
//    if(x >= MAX_SIZE || y >= MAX_SIZE)
//    {
//      printf("0\n");
//    }
//    else
//    {
//      printf("%d\n", field[y][x]);
//    }
//  }
//  printf("\n");
//}
//
//int main()
//{
//  int QWE;
//#ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  scanf("%d", &QWE);
//#else
//  QWE = 1;
//#endif
//  for(int T = 0; T < QWE; T++)
//  {
//    ReadData();
//    Solve();
//    WriteData();
//  }
//  return 0;
//}
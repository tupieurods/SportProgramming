#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
//int *swapTable;
//__int64 **matrix, *answer;
int swapTable[505];
__int64 matrix[505][505], answer[505];

void ReadData()
{
  scanf("%d", &n);
  //matrix = new __int64*[n];
  //swapTable = new int[n];
  for(int i = 0; i < n; i++)
  {
    //matrix[i] = new __int64[n];
    for(int j = 0; j < n; j++)
    {
      scanf("%I64d", &matrix[i][j]);
    }
  }
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &swapTable[n - i - 1]);
    swapTable[n - i - 1]--;
  }
}

inline __int64 getMatrixVal(int x, int y)
{
  int realX = swapTable[x], realY = swapTable[y];
  return matrix[realY][realX];
}

inline void setMatrixVal(int x, int y, __int64 val)
{
  int realX = swapTable[x], realY = swapTable[y];
  matrix[realY][realX] = val;
}

inline __int64 min(__int64 a, __int64 b)
{
  return a < b ? a : b;
}

void Solve()
{
  //answer = new __int64[n];
  for(int k = 0; k < n; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        setMatrixVal(j, i, min(getMatrixVal(j, i),
          getMatrixVal(k, i) + getMatrixVal(j, k)));
      }
    }
    answer[k] = 0LL;
    for(int i = 0; i <= k; i++)
    {
      for(int j = 0; j <= k; j++)
      {
        if(i != j)
          answer[k] += getMatrixVal(j ,i);
      }
    }
  }
}

void WriteData()
{
  for(int i = n - 1; i >= 0; i--)
  {
    printf("%I64d ", answer[i]);
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
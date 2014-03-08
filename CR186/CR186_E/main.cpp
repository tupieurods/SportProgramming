#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma warning(disable: 4996)

int n, m;
int inputNumber[2][100009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(inputNumber, 0, sizeof(inputNumber));
  int value;
  for(int T = 0; T < 2; T++)
  {
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &value);
      inputNumber[T][value]++;
    }
  }
}

int answer[100009];
int myStack[200009];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  int stackCnt = 0;
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j < inputNumber[0][i]; j++)
    {
      myStack[stackCnt] = i;
      stackCnt++;
    }
    for(int j = 0; j < inputNumber[1][m - 1 - i]; j++)
    {
      if(stackCnt > 0 && myStack[stackCnt - 1] >= 0)
      {
        stackCnt--;
        answer[myStack[stackCnt] + (m - 1 - i)]++;
      }
      else
      {
        myStack[stackCnt] = -(m - 1 - i);
        stackCnt++;
      }
    }
  }
  if(stackCnt > 0)
  {
    int cnt = stackCnt / 2;
    for(int i = 0; i < cnt; i++)
    {
      answer[(-myStack[i] + myStack[stackCnt - 1 - i]) % m]++;
    }
  }
}

void WriteData()
{
  for(int i = m - 1; i >= 0; i--)
  {
    for(int j = 0; j < answer[i]; j++)
    {
      printf("%d ", i);
    }
  }
  printf("\n");
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
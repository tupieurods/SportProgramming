#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n, k;
int matrix[2009][2009];
long double treg[2001][2001];

void ReadData()
{
  scanf("%d %d", &n, &k);
  memset(matrix, 0xFF, sizeof(matrix));
  for(int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
      matrix[j][i] = matrix[i][j];
    }
  }
}

void fillTreg()
{
  memset(treg, 0, sizeof(treg));
  treg[0][1] = 1;
  treg[1][1] = 1;
  treg[1][2] = 1;
  for(int i = 2; i < 2001; i++)
  {
    for(int j = 0; j < i + 1; j++)
    {
      treg[i][j + 1] = treg[i - 1][j] + treg[i - 1][j + 1];
    }
  }
}

long double answerTop, answerDown;

void Solve()
{
  answerTop = 0;
  answerDown = 0;
  for(int i = 0; i < n; i++)
  {
    int cnt = 0;
    __int64 sum = 0;
    for(int j = 0; j < n; j++)
    {
      if(matrix[i][j] != -1)
      {
        cnt++;
        sum += matrix[i][j];
      }
    }
    if(cnt >= k)
    {
      answerTop += treg[cnt][k + 1] / cnt * sum;
      answerDown += treg[cnt][k + 1];
    }
  }
}

void WriteData()
{
  printf("%I64d\n", (unsigned __int64)floor(answerTop * k / answerDown + 1e-3));
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n2000 1999\n");
    for(int i = 0; i < 1999; i++)
    {
      for(int j = i + 1; j < 1999; j++)
      {
        printf("1000000000");
      }
      printf("\n");
    }
    return 0;
  }
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  fillTreg();
  //printf("%.0lf\n", treg[40][15 + 1]);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
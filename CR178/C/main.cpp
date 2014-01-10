#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__int64 answer;
int n, m;
const int mod = 1000000007;
int *arr;
__int64** Treg;

void ReadData()
{
  scanf("%d %d", &n, &m);
  arr = new int[n];
  memset(arr, 0, sizeof(int) * n);
  for(int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    arr[tmp - 1] = 1;
  }
}

void CalcTreg()
{
  Treg = new __int64*[1005];
  for(int i = 0; i < 1005; i++)
  {
    Treg[i] = new __int64[1005];
    memset(Treg[i], 0, sizeof(__int64) * 1005);
  }
  Treg[0][1] = 0;
  Treg[1][1] = 1; Treg[1][2] = 1;
  for(int i = 2; i < 1005; i++)
  {
    //Treg[i][0] = 1;
    for(int j = 1; j <= i + 1; j++)
    {
      Treg[i][j] = (Treg[i - 1][j - 1] + Treg[i - 1][j]) % mod;
    }
  }
  /*for(int i = 1; i < 14; i++)
  {
    //Treg[i][0] = 1;
    for(int j = 1; j <= i + 1; j++)
    {
      printf("%I64d ", Treg[i][j]);
    }
    printf("\n");
  }*/
}

__int64 CalcC(int cnt, int k)
{
  return Treg[cnt][k + 1];
  //return 0;
  /*if(cnt == 897)
  {
    printf("Hi\n");
  }
  if(cnt < k) throw;

  if(cnt == k)
    return 1;

  __int64 result = 1;
  int start, finish;
  if(k > cnt - k)
  {
    start = k + 1;
    finish = cnt - k;
  }
  else
  {
    start = cnt - k + 1;
    finish = k;
  }
  __int64 second = 2LL;
  for(__int64 i = start; i <= cnt; i++)
  {
    int current = i;
    while(second <= finish && current % second == 0)
    {
      current /= second;
      second++;
    }
    result *= current;
  }
  while(second <= finish && result % second == 0)
  {
    result /= second;
    second++;
  }
  if(result == 0) throw;
  return (result % mod);*/
}

void Solve()
{
  answer = 1;
  if(n == m)
  {
    return;
  }
  int len = 0;
  int current = 0;
  int totalLen = 0;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] == 1)
    {
      totalLen += len;
      //Если две зажжённые лампочки рядом или это первый отрезок
      if(len == 0 || current == 0)
      {
        current++;
        len = 0;
        continue;
      }
      answer *= CalcC(totalLen, len);
      answer %= mod;
      for(int i = 0; i < len - 1; i++)
      {
        answer *= 2LL;
        answer %= mod;
      }
      current++;
      len = 0;
    }
    else
    {
      len++;
    }
  }
  if(len != 0)//Если последняя последовательность не имеет конца
  {
    answer *= CalcC(totalLen + len, len);
    answer %= mod;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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
  CalcTreg();
  //printf("%d\n", CalcC(9, 3));
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[109];
vector<int> primes;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int fact[69];
int dp[109][(1 << 17) + 9];
pair<int, int> dp2[109][(1 << 17) + 9];

void Solve()
{
  memset(dp, 0x7F, sizeof(dp));
  memset(dp, 0, sizeof(int) * ((1 << 17) + 9));
  for(int i = 0; i < 109; i++)
  {
    for(int j = 0; j < (1 << 17) + 9; j++)
    {
      dp2[i][j].first = 1;
    }
  }
  //dp[X][Y]
  //X-сколько элементов в последовательности
  //Y-какие простые уже использованы
  for(int i = 1; i <= n; i++)
  {
    for(int k = 1; k < 60; k++)
    {
      int X = (~fact[k]) & ((1 << 17) - 1);//Исключили биты которые отвечают за простые множетели
      //в разложении k
      for(int s = X; ; s = (s - 1) & X)//Генерируем все перестановки, которые используют только биты из X
      {
        if(abs(a[i - 1] - k) + dp[i - 1][s] < dp[i][s | fact[k]])
        {
          dp[i][s | fact[k]] = abs(a[i - 1] - k) + dp[i - 1][s];
          dp2[i][s | fact[k]].first = k;
          dp2[i][s | fact[k]].second = s;
        }
        if(s == 0)
        {
          break;
        }
      }
    }
  }
}

void g(int mask, int idx)
{
  if(idx == 0)
  {
    return;
  }
  g(dp2[idx][mask].second, idx - 1);
  printf("%d ", dp2[idx][mask].first);
}

void WriteData()
{
  int mask;
  int minimal = INT_MAX;
  for(int i = 0; i < (1 << 17) + 9; i++)
  {
    if(dp[n][i] < minimal)
    {
      mask = i;
      minimal = dp[n][i];
    }
  }
  g(mask, n);
  printf("\n");
}

int main()
{
  primes.push_back(2);
  for(int i = 3; i < 60; i++)
  {
    bool flag = true;
    for(int j = 2; j < i; j++)
    {
      if((i % j) == 0)
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      primes.push_back(i);
    }
  }
  memset(fact, 0, sizeof(fact));
  int primesCnt = primes.size();
  for(int i = 2; i < 60; i++)
  {
    for(int j = 0; j < primesCnt; j++)
    {
      if((i % primes[j]) == 0)
      {
        fact[i] |= 1 << j;
      }
    }
  }
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
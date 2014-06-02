#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

const int MOD = 1000000007;
int n, m;
int answer[100009], b[109][100009];
int fact[100009], inv[100009];

int getComb(int v1, int v2)
{
  return (((fact[v2] * 1LL * inv[v1]) % MOD) * 1LL * inv[v2 - v1]) % MOD;
}

void ReadData()
{
  memset(answer, 0, sizeof(answer));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &answer[i]);
  }
}

void Solve()
{
  memset(b, 0, sizeof(b));
  for(int i = 0; i < m; i++)
  {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;
    r--;
    b[k + 1][l]++;
    for(int j = 1; j <= k + 1; j++)
    {
      b[j][r + 1] -= getComb(k + 1 - j, r - l + 1 + k - j);
      while(b[j][r + 1] <= -MOD)
      {
        b[j][r + 1] += MOD;
      }
    }
  }
  for(int T = 101; T > 0; T--)
  {
    b[T][0] = (b[T][0] + b[T + 1][0]) % MOD;
    for(int i =1; i < n; i++)
    {
      b[T][i] = ((b[T][i - 1] + b[T][i]) % MOD + b[T + 1][i]) % MOD;
    }
  }
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    int val = (answer[i] + b[1][i]) % MOD;
    while(val < 0)
    {
      val += MOD;
    }
    printf("%d ", val);
  }
  printf("\n");
}

__int64 binPow(__int64 value, int power)
{
  if(power == 0)
  {
    return 1;
  }
  __int64 result = binPow(value, power / 2);
  result = (result * result) % MOD;
  return power % 2 == 0 ? result : (result * value) % MOD;
}

int main()
{
  //data for comb precalc
  fact[0] = 1;
  inv[0] = 1;//binPow(1, MOD - 2);
  for(int i = 1; i < 100009; i++)
  {
    fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    inv[i] = binPow(fact[i], MOD - 2);
  }
  //data for comb precalc
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
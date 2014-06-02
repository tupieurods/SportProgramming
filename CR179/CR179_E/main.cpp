#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

#pragma warning(disable: 4996)

struct conf
{
  int a, b, side;
  conf(int a, int b, int side):a(a), b(b), side(side)
  {
  }
};

const __int64 MOD = 1000000007LL;

int n, k;
int people[2];
__int64 fact[59], inv[59];

void ReadData()
{
  scanf("%d %d", &n, &k);
  people[0] = people[1] = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    people[val == 50 ? 0 : 1]++;
  }
}

__int64 GetCombo(int a, int b)
{
  return (((fact[a] * inv[b]) % MOD) * inv[a - b]) % MOD;
}

__int64 answer;
int cnt;
int dp[59][59][2];
__int64 dpV[59][59][2];
bool used[59][59][2];

/*int f(int a, int b, int side)
{
  if(dp[a][b][side] != -1)
  {
    return dp[a][b][side];
  }
  used[a][b][side] = true;
  int result = MOD + 100;
  int factor, newA, newB;
  if(side == 1)
  {
    factor = 1;
    newA = people[0] - a;
    newB = people[1] - b;
  }
  else
  {
    factor = -1;
    newA = a;
    newB = b;
  }

  for(int i = 0; i <= newA; i++)
  {
    for(int j = 0; j <= newB; j++)
    {
      if((i + j != 0) && (50 * i + 100 * j <= k) && !used[a + factor * i][b + factor * j][side ^ 1])
      {
        result = std::min(result, 1 + f(a + factor * i, b + factor * j, side ^ 1));
      }
    }
  }
  dp[a][b][side] = result;
  return result;
}*/

__int64 g(int a, int b, int side)
{
  if(dpV[a][b][side] != -1)
  {
    return dpV[a][b][side];
  }
  __int64 result = 0;
  int factor, newA, newB;
  if(side == 1)
  {
    factor = 1;
    newA = people[0] - a;
    newB = people[1] - b;
  }
  else
  {
    factor = -1;
    newA = a;
    newB = b;
  }
  for(int i = 0; i <= newA; i++)
  {
    for(int j = 0; j <= newB; j++)
    {
      if((i + j != 0) && (50 * i + 100 * j <= k) && (dp[a][b][side] == dp[a + factor * i][b + factor * j][side ^ 1] + 1))
      {
        //printf("goto: %d %d %d. Test: %d %d\n", a + factor * i, b + factor * j, side ^ 1, dp[a][b][side], dp[a + factor * i][b + factor * j][side ^ 1]);
        result = (result + ((GetCombo(newA, i) * GetCombo(newB, j)) % MOD) * g(a + factor * i, b + factor * j, side ^ 1)) % MOD;
      }
    }
  }
  dpV[a][b][side] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  memset(dpV, 0xFF, sizeof(dpV));
  memset(used, 0, sizeof(used));
  dp[0][0][1] = 0;
  dpV[0][0][1] = 1;
  //cnt = f(people[0], people[1], 0);
  queue<conf> q;
  q.push(conf(0, 0, 1));
  while(!q.empty())
  {
    conf current = q.front();
    q.pop();
    int factor, newA, newB;
    if(current.side == 1)
    {
      factor = 1;
      newA = people[0] - current.a;
      newB = people[1] - current.b;
    }
    else
    {
      factor = -1;
      newA = current.a;
      newB = current.b;
    }
    for(int i = 0; i <= newA; i++)
    {
      for(int j = 0; j <= newB; j++)
      {
        if((i + j != 0) && (50 * i + 100 * j <= k) && dp[current.a + factor * i][current.b + factor * j][current.side ^ 1] == -1)
        {
          dp[current.a + factor * i][current.b + factor * j][current.side ^ 1] = dp[current.a][current.b][current.side] + 1;
          q.push(conf(current.a + factor * i, current.b + factor * j, current.side ^ 1));
        }
      }
    }
  }
  if(dp[people[0]][people[1]][0] == -1)
  {
    cnt = -1;
    answer = 0;
  }
  else
  {
    cnt = dp[people[0]][people[1]][0];
    answer = g(people[0], people[1], 0);
  }
}

void WriteData()
{
  printf("%d %I64d\n", cnt, answer);
}

__int64 BinPow(__int64 val, int power)
{
  if(power == 0)
  {
    return 1LL;
  }
  __int64 result = BinPow(val, power / 2);
  result = (result * result) % MOD;
  return (power % 2 == 1) ? (result * val) % MOD : result;
}

void precalc()
{
  fact[0] = 1;
  inv[0] = 1;
  for(int i = 1; i < 59; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = BinPow(fact[i], MOD - 2);
  }
}

int main()
{
  precalc();
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
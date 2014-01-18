#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

const int wide = 4;
int n;
const int mod = 1000000009;
vector<int> combinations[1 << wide];

void ReadData()
{
  scanf("%d", &n);
}

int answer;
int dp[1 << wide][1009];

int f(int mask, int level)
{
  if(level == n)
  {
    return mask == 0 ? 1 : 0;
  }
  if(dp[mask][level] != -1)
  {
    return dp[mask][level];
  }
  int result = 0;
  for(vector<int>::iterator it = combinations[mask].begin(); it != combinations[mask].end(); it++)
  {
    result = (result + f(*it, level + 1)) % mod;
  }
  dp[mask][level] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answer = f(0, 0);
}

void WriteData()
{
  printf("%d\n", answer);
}

int genFor;

void genCombination(int current, int bottom)
{
  if(current == (1 << wide) - 1)
  {
    combinations[genFor].push_back(bottom);
    return;
  }
  for(int i = 0; i < wide; i++)
  {
    if((current & (1 << i)) == 0)
    {
      if((i != wide - 1) && ((current & (1 << (i + 1))) == 0))
      {
        genCombination(current | (3 << i), bottom);
      }
      genCombination(current | (1 << i), bottom | (1 << i));
      return;
    }
  }
}

int main()
{
  for(int i = 0; i < (1 << wide); i++)
  {
    genFor = i;
    genCombination(i, 0);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m;
int s[109];
char actions[29];
int player[29];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &s[i]);
  }
  scanf("%d%*c", &m);
  memset(player, 0, sizeof(player));
  for(int i = 0; i < m; i++)
  {
    scanf("%c %d%*c", &actions[i], &player[i]);
  }
}

int comparer(const void *v1, const void *v2)
{
  return *(int*)v2 - *(int*)v1;
}

int answer;
int dp[1 << 20];
bool dpSet[1 << 20];

int f(int mask, int usedCount)
{
  if(usedCount == m)
  {
    return 0;
  }
  if(dpSet[mask])
  {
    return dp[mask];
  }
  int result = player[usedCount] == 1 ? INT_MIN : INT_MAX;
  if(actions[usedCount] == 'p')
  {
    int pos = 0;
    while(((1 << pos) & mask) != 0)
    {
      pos++;
    }
    result = (player[usedCount] == 1 ? s[pos] : -s[pos]) + f(mask | (1 << pos), usedCount + 1);
  }
  else
  {
    for(int i = 0; i < m; i++)
    {
      if(((1 << i) & mask) != 0)
      {
        continue;
      }
      if(player[usedCount] == 1)
      {
        result = std::max(result, f(mask | (1 << i), usedCount + 1));
      }
      else
      {
        result = std::min(result, f(mask | (1 << i), usedCount + 1));
      }
    }
  }
  dpSet[mask] = true;
  dp[mask] = result;
  return result;
}

void Solve()
{
  qsort(s, n, sizeof(int), comparer);
  memset(dpSet, 0, sizeof(dpSet));
  answer = f(0, 0);
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
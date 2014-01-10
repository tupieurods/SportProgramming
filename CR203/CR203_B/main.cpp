#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
bool objects[100009];
int a[100009];
int cnt[100009];

void ReadData()
{
  scanf("%d", &n);
  memset(objects, 0, sizeof(objects));
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    objects[i + 1] = val == 1;
  }
  memset(cnt, 0, sizeof(cnt));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i + 1]);
    cnt[a[i + 1]]++;
  }
}

int dp[100009];
int answerInd;

int f(int current)
{
  if(dp[current] != -1)
  {
    return dp[current];
  }
  int result = 1;
  if(a[current] != 0 && cnt[a[current]] == 1)
  {
    result = 1 + f(a[current]);
  }
  dp[current] = result;
  return result;
}

void Solve()
{
  memset(dp, 0xFF, sizeof(dp));
  answerInd = 1;
  for(int i = 0; i < n; i++)
  {
    if(objects[i + 1])
    {
      f(i + 1);
      if(dp[i + 1] > dp[answerInd])
      {
        answerInd = i + 1;
      }
    }
  }
}

void g(int current)
{
  if(a[current] != 0 && cnt[a[current]] == 1)
  {
    g(a[current]);
  }
  printf("%d ", current);
}

void WriteData()
{
  printf("%d\n", dp[answerInd]);
  g(answerInd);
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
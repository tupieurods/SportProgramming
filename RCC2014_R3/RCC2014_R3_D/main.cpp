#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int n, d;
int a[109], b[109], c[109];

void ReadData()
{
  scanf("%d %d", &n, &d);
  memset(b, 0, sizeof(b));
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answerV[109];
bool answer;
int dp[1000009];

void Solve()
{
  answer = false;
  memset(dp, 0xFF, sizeof(dp));
  memset(c, 0, sizeof(c));
  dp[0] = -2;
  for(int i = 0; i < n; i++)
  {
    b[i] = b[i == 0 ? 0 : i - 1] + a[i];
    answerV[i] = n - i;
    d -= answerV[i] * a[i];
    if(d < 0)
    {
      break;
    }
  }
  if(d <= 0)
  {
    if(d == 0)
    {
      answer = true;
    }
    return;
  }
  for(int i = 1; i <= d; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i - b[j] >= 0 && dp[i - b[j]] != -1)
      {
        dp[i] = j;
      }
    }
  }
  if(dp[d] != -1)
  {
    answer = true;
    while(d != 0)
    {
      c[dp[d]]++;
      d -= b[dp[d]];
    }
    int adder = 0;
    for(int i = n -1; i >= 0; i--)
    {
      adder += c[i];
      answerV[i] += adder;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < n; i++)
    {
      printf("%d ", answerV[i]);
    }
    printf("\n");
  }
  else
  {
    printf("NO\n");
  }
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
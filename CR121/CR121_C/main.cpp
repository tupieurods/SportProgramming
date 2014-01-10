#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct king
{
  char first, last;
  int len;
};

int n;
king kings[500009];

void ReadData()
{
  scanf("%d%*c", &n);
  char str[19];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    kings[i].len = strlen(str);
    kings[i].first = str[0];
    kings[i].last = str[kings[i].len - 1];
  }
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int dp[30][30], answer;

void Solve()
{
  memset(dp, 0, sizeof(dp));
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < 26; j++)
    {
      if(dp[j][(int)(kings[i].first - 'a')] > 0//Если получим продолжение
        || j == (int)(kings[i].first - 'a'))//или начало новой династии
      {
        dp[j][(int)(kings[i].last - 'a')] = max(dp[j][(int)(kings[i].last - 'a')], dp[j][(int)(kings[i].first - 'a')] + kings[i].len);
      }
    }
  }
  for(int i = 0; i < 26; i++)
  {
    answer = max(answer, dp[i][i]);
  }
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
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
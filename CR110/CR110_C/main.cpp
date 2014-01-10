#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[2009], str2[2009];
int len1, len2;

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  len1 = strlen(str1);
  len2 = strlen(str2);
}

int dp[2009][2009];

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int f(int index, int pos)
{
  if(pos > len2)
    throw;
  if(index >= len1)
  {
    return len2 - pos + 1;
  }
  if(pos == len2)
  {
    return (int)(str1[index] != str2[pos - 1]);
  }
  if(dp[index][pos] != -1)
  {
    return dp[index][pos];
  }
  int equal = (int)(str1[index] != str2[pos - 1]);
  int result = equal + len2 - pos;
  result = min(result, equal + f(index + 1, pos + 1));
  dp[index][pos] = result;
  return result;
}

int answer;

void Solve()
{
  answer = 10000;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < len1; i++)
  {
    for(int j = 1; j <= len2; j++)
    {
      int current = f(i, j);
      if(j > 1)
        current += j - 1;
      answer = min(answer, current);
    }
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
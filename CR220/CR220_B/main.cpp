#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[100009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

__int64 answer;

void Solve()
{
  answer = 0;
  int cnt = 0;
  for(int i = 0; i < len; i++)
  {
    if(i + 1 < len && (int)(str[i] - '0') + (int)(str[i + 1] - '0') == 9)
    {
      if(cnt == 0)
      {
        cnt = 2;
      }
      else
      {
        cnt++;
      }
    }
    else if(cnt != 0)
    {
      __int64 mul = cnt % 2 == 0 ? 1 : (cnt + 1) / 2;
      if(answer == 0)
      {
        answer = mul;
      }
      else
      {
        answer *= mul;
      }
      cnt = 0;
    }
  }
  if(answer == 0)
  {
    answer = 1;
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
  scanf("%d%*c", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
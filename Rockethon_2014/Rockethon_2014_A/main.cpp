#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[109];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

int answer;

void Solve()
{
  answer = 0;
  int cnt = 0;
  char current = str[0];
  for(int i = 0; i < len; i++)
  {
    if(str[i] == current)
    {
      cnt++;
    }
    else
    {
      if(cnt % 2 == 0)
      {
        answer++;
      }
      current = str[i];
      cnt = 1;
    }
  }
  if(cnt % 2 == 0)
  {
    answer++;
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
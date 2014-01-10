#include <stdio.h>
#include <string.h>

char str[200005];
const int mod = 1000000007;

void ReadData()
{
  memset(str, 0, sizeof(str));
  scanf("%s", &str);
}

int answer;

void Solve()
{
  int len = strlen(str);
  int center = len / 2;
  answer = 1;
  int toRemove = 1;
  for(int i = 0; i < len; i++)
  {
    if(str[i] == '?')
    {
      answer *= 2;
      answer %= mod;
    }
  }
  for(int i = 0; i < center; i++)
  {
    if(str[i] == '?')
    {
      if(str[i + center] == '?')
      {
        toRemove *= 2;
        toRemove %= mod;
      }
      continue;
    }
    if(str[i + center] == '?')
      continue;

    if(str[i] != str[i + center])
    {
      toRemove = 0;
      break;
    }
  }
  answer -= toRemove;
  answer %= mod;
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  scanf("%d%*c", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}
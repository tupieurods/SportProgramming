#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000009];

void ReadData()
{
  scanf("%s%*c", str);
}

int answer;

void Solve()
{
  int len = strlen(str);
  answer = 0;
  int idx = 0;
  bool flag = true;
  for(int i = 0; i < len; i++)
  {
    if(str[i] == 'M')
    {
      flag = false;
      continue;
    }
    if(flag)
    {
      idx++;
      continue;
    }
    int current = i - idx;
    if(current > answer)
    {
      answer = current;
    }
    else
    {
      answer++;
    }
    idx++;
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
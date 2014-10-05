#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int l[4];

void ReadData()
{
  char str[109];
  for(int i = 0; i < 4; i++)
  {
    scanf("%s%*c", str);
    l[i] = strlen(str) - 2;
  }
}

bool isAwesome(int idx)
{
  int cnt = 0;
  for(int i = 0; i < 4; i++)
  {
    if(i != idx)
    {
      if(l[idx] * 2 <= l[i])
      {
        cnt++;
      }
    }
  }
  if(cnt != 3)
  {
    cnt = 0;
    for(int i = 0; i < 4; i++)
    {
      if(i != idx)
      {
        if(l[idx] >= l[i] * 2)
        {
          cnt++;
        }
      }
    }
  }
  return cnt == 3;
}

char answer;

void Solve()
{
  int cnt = 0;
  for(int i = 0; i < 4; i++)
  {
    if(isAwesome(i))
    {
      answer = 'A' + i;
      cnt++;
    }
  }
  if(cnt != 1)
  {
    answer = 'C';
  }
}

void WriteData()
{
  printf("%c\n", answer);
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
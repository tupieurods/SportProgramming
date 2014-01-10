#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

__int64 l, r;

void Solve()
{
  l = 0, r = 0;
  __int64 index = -1;
  for(int i = 0; i < len; i++)
  {
    if(str[i] != '^' && index == -1)
    {
      continue;
    }
    if(index == -1)
    {
      index = i;
      continue;
    }
    if(str[i] == '=')
    {
      continue;
    }
    r += (i - index) * ((__int64)(str[i] - '0'));
  }
  for(int i = 0; i < index; i++)
  {
    if(str[i] == '=')
    {
      continue;
    }
    l += (index - i) * ((__int64)(str[i] - '0'));
  }
}

void WriteData()
{
  if(l == r)
  {
    printf("balance\n");
  }
  else if(l > r)
  {
    printf("left\n");
  }
  else
  {
    printf("right\n");
  }
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
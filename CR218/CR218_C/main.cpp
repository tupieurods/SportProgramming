#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[109];
__int64 r;
__int64 n[3], p[3];
int a[3];

void ReadData()
{
  scanf("%s%*c", str);
  for(int i = 0; i < 3; i++)
  {
    scanf("%I64d", &n[i]);
  }
  for(int i = 0; i < 3; i++)
  {
    scanf("%I64d", &p[i]);
  }
  scanf("%I64d", &r);
}

bool check()
{
  return a[0] <= n[0] && a[1] <= n[1] && a[2] <= n[2];
}

bool check2()
{
  return (a[0] == 0 || n[0] == 0) && (a[1] == 0 || n[1] == 0) && (a[2] == 0 || n[2] == 0);
}

__int64 answer;

void Solve()
{
  int len = strlen(str);
  memset(a, 0, sizeof(a));
  for(int i = 0; i < len; i++)
  {
    if(str[i] == 'B')
    {
      a[0]++;
    }
    else if(str[i] == 'S')
    {
      a[1]++;
    }
    else
    {
      a[2]++;
    }
  }
  //ѕопробовать построить из того что есть
  answer = 0;
  while(check())
  {
    answer++;
    for(int i = 0; i < 3; i++)
    {
      n[i] -= a[i];
    }
  }
  int b[3];
  //printf("step1\n");
  while(!check2())
  {
    __int64 toAdd = 0;
    memset(b, 0, sizeof(b));
    for(int i = 0; i < 3; i++)
    {
      if(a[i] >= n[i])
      {
        toAdd += (a[i] - n[i]) * p[i];
      }
    }
    if(toAdd <= r)
    {
      r -= toAdd;
      answer++;
      for(int i = 0; i < 3; i++)
      {
        n[i] = std::max(0LL, n[i] - a[i]);
      }
    }
    else
    {
      break;
    }
  }
  __int64 sum = a[0] * p[0] + a[1] * p[1] + a[2] * p[2];
  answer += r / sum;
}

void WriteData()
{
  printf("%I64d\n", answer);
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
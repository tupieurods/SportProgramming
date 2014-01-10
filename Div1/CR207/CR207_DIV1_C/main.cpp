#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int a[5];

void ReadData()
{
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a[val]++;
  }
}

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

int answer;

void Solve()
{
  answer = min(a[1], a[2]);
  a[1] -= answer;
  a[2] -= answer;
  a[3] += answer;
  if(a[1] != 0)
  {
    while(a[1] >= 3)
    {
      a[1] -= 3;
      a[3]++;
      answer += 2;
    }
    if(a[1] == 2)
    {
      if(a[4] != 0)
      {
        answer += 2;
        a[4]--;
        a[3] += 2;
        a[1] = 0;
      }
    }
    for(int i = 0; i < a[1]; i++)
    {
      if(a[3] != 0)
      {
        answer++;
        a[3]--;
        a[1]--;
        a[4]++;
        i--;
      }
    }
    if(a[1] == 1)
    {
      if(a[4] >= 2)
      {
        answer += 2;
        a[4] -= 2;
        a[3] += 3;
        a[1] = 0;
      }
    }
    else if(a[1] == 2)
    {
      if(a[4] != 0)
      {
        answer += 2;
        a[4]--;
        a[3] += 2;
        a[1] = 0;
      }
    }
  }
  else if(a[2] != 0)
  {
    while(a[2] >= 3)
    {
      a[2] -= 3;
      a[3] += 2;
      answer += 2;
    }
    for(int i = 0; i < 2; i++)
    {
      if(a[2] == 2)
      {
        answer += 2;
        a[4]++;
        a[2] = 0;
      }
      while(a[2] != 0 && a[4] != 0)
      {
        a[4]--;
        a[3] += 2;
        a[2]--;
        answer++;
      }
      while(a[2] != 0 && a[3] >= 2)
      {
        a[3] -= 2;
        a[4] += 2;
        a[2]--;
        answer += 2;
      }
    }
  }
  if(a[1] != 0 || a[2] != 0)
  {
    answer = -1;
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
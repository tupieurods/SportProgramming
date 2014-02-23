#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int l, s, fin, n;
int c[59];

void ReadData()
{
  scanf("%d %d %d %d", &l, &s, &fin, &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
    c[i] %= l;
  }
}

int answer;
int dp1[59][59];
int dp2[59][59];

int f(int st_n, int current)
{
  if(st_n == n)
  {
    if(current == fin)
    {
      return 1;
    }
    return 0;
  }
  if(dp1[st_n][current] != -1)
  {
    return dp1[st_n][current];
  }
  //D
  int nxt = current - c[st_n];
  if(nxt <= 0)
  {
    nxt = l + nxt;
  }
  int r1 = f(st_n + 1, nxt);
  dp2[st_n][current] += r1;
  //U
  nxt = current + c[st_n];
  if(nxt > l)
  {
    nxt %= l;
  }
  int r2 = f(st_n + 1, nxt);
  if(r2 != 0)
  {
    dp2[st_n][current] += 5;
  }
  int result = r1 + r2 > 0 ? 1 : 0;
  dp1[st_n][current] = result;
  return result;
}

void Solve()
{
  memset(dp1, 0xFF, sizeof(dp1));
  memset(dp2, 0, sizeof(dp2));
  answer = f(0, s);
}

__int64 checker;
__int64 dp3[59][59];

__int64 g(int st_n, int current)
{
  if(st_n == n)
  {
    return 1;
  }
  if(dp3[st_n][current] != -1)
  {
    return dp3[st_n][current];
  }
  __int64 result = 0;
  if(dp2[st_n][current] == 1)
  {
    int nxt = current - c[st_n];
    if(nxt <= 0)
    {
      nxt = l + nxt;
    }
    result = g(st_n + 1, nxt);
  }
  else if(dp2[st_n][current] == 5)
  {
    int nxt = current + c[st_n];
    if(nxt > l)
    {
      nxt %= l;
    }
    result = g(st_n + 1, nxt);
  }
  else if(dp2[st_n][current] == 6)
  {
    int nxt = current - c[st_n];
    if(nxt <= 0)
    {
      nxt = l + nxt;
    }
    result = g(st_n + 1, nxt);
    nxt = current + c[st_n];
    if(nxt > l)
    {
      nxt %= l;
    }
    result += g(st_n + 1, nxt);
  }
  dp3[st_n][current] = result;
  return result;
}

void g2(__int64 val, int st)
{
  if(st == n)
  {
    return;
  }
  g2(val >> 1, st + 1);
  if((val & 1LL) == 0)
  {
    printf("D");
  }
  else
  {
    printf("U");
  }
}

void WriteData()
{
  checker = 0;
  memset(dp3, 0xFF, sizeof(dp3));
  if(answer == 0)
  {
    printf("0");
  }
  else
  {
    int st_n = 0;
    int pos = s;
    while(st_n != n)
    {
      checker <<= 1;
      if(dp2[st_n][pos] == 1)
      {
        int nxt = pos - c[st_n];
        if(nxt <= 0)
        {
          nxt = l + nxt;
        }
        pos = nxt;
      }
      else if(dp2[st_n][pos] == 5)
      {
        checker |= 1;
        int nxt = pos + c[st_n];
        if(nxt > l)
        {
          nxt %= l;
        }
        pos = nxt;
      }
      else if(dp2[st_n][pos] == 6)
      {
        int nxt = pos - c[st_n];
        if(nxt <= 0)
        {
          nxt = l + nxt;
        }
        pos = nxt;
      }
      st_n++;
    }
    __int64 wtf = g(0, s);
    printf("%I64d ", wtf);
    g2(checker, 0);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("HACK.IN", "r", stdin);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
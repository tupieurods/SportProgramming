#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, l, r, ql, qr;
int w[100009];
__int64 sum;

void ReadData()
{
  scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
  sum = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &w[i]);
    sum += w[i] * r;
  }
}

__int64 answer;

inline __int64 min(__int64 v1, __int64 v2)
{
  return v1 < v2 ? v1 : v2;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

void Solve()
{
  answer = sum + qr * (n - 1LL);
  __int64 sum2 = 0;
  for(int i = 0; i < n; i++)
  {
    sum2 += w[i] * l;
    sum -= w[i] * r;
    __int64 current = sum + sum2;
    int froml = i + 1;
    int fromr = n - froml;
    int mul = 0;
    if(froml <= fromr)
    {
      mul = max(0, fromr - froml - 1);
      current += qr * mul;
    }
    else
    {
      mul = max(0, froml - fromr - 1);
      current += ql * mul;
    }
    answer = min(answer, current);
  }
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
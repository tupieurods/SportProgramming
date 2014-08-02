#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

__int64 n, k, d1, d2;

void ReadData()
{
  scanf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
}

bool tryToSolve(__int64 _d1, __int64 _d2)
{
  __int64 w1, w2, w3;
  w3 = (k - _d1 - 2 * _d2) / 3LL;
  w2 = _d2 + w3;
  w1 = _d2 + _d1 + w3;
  if(((w1 + w2 + w3) != k)
    || w1 < 0 || w2 < 0 || w3 < 0
    || (w1 - w2 != _d1)
    || (w2 - w3 != _d2))
  {
    return false;
  }
  __int64 maximal = std::max(w1, std::max(w2, w3));
  __int64 cnt = 3LL * maximal - (w1 + w2 + w3);
  if(cnt > n - k)
  {
    return false;
  }
  if((n - cnt - k) % 3 != 0)
  {
    return false;
  }
  return true;
}

bool answer;

void Solve()
{
  if(n % 3 != 0)
  {
    answer = false;
    return;
  }
  answer = tryToSolve(d1, d2)
    || tryToSolve(d1, -d2)
    || tryToSolve(-d1, d2)
    || tryToSolve(-d1, -d2);
}

void WriteData()
{
  if(answer)
  {
    printf("yes\n");
  }
  else
  {
    printf("no\n");
  }
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
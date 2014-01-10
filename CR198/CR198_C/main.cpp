#include <stdio.h>
#include <stdlib.h>

int n;
__int64 a[100009];
__int64 answerTop, answerBottom;

void ReadData()
{
  scanf("%d", &n);
  answerBottom = n;
  answerTop = 0LL;
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &a[i]);
    answerTop += a[i];
  }
}

__int64 Nod(__int64 v1, __int64 v2)
{
  if(v2 == 0LL)
  {
    return v1;
  }
  return Nod(v2, v1 % v2);
}

int compare(const void *v1, const void *v2)
{
  return *(__int64*)v1 - *(__int64*)v2;
}

void Solve()
{
  /*for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j)
      {
        continue;
      }
      answerTop += abs(a[i] - a[j]);
      printf("%d %d\n", i + 1, j + 1);
    }
  }*/
  qsort(a, n, sizeof(__int64), compare);
  __int64 toAdd = 0LL, s = a[0];
  for(int i = 1; i < n; i++)
  {
    toAdd += a[i] * i - s;
    s += a[i];
  }
  answerTop += 2LL * toAdd;
  __int64 nod = Nod(answerTop, answerBottom);
  answerTop /= nod;
  answerBottom /= nod;
}

void WriteData()
{
  printf("%I64d %I64d\n", answerTop, answerBottom);
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
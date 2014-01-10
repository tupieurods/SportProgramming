#include <stdio.h>
#include <stdlib.h>

__int64 *a;
__int64 answer;
int cnt;

int compare(const void *v1, const void *v2)
{
  return *(__int64*)v2 - *(__int64*)v1;
}

void ReadData()
{
  scanf("%d", &cnt);
  a = new __int64[cnt];
  for(int i = 0; i < cnt; i++)
  {
    scanf("%I64d", &a[i]);
  }
  qsort(a, cnt, sizeof(__int64), compare);
  __int64 sum = 0LL;
  for(int i = 0; i < cnt; i++)
  {
    sum += a[i];
    a[i] = sum;
  }
}

void Solve()
{
  answer = a[0];
  int copy = cnt;
  int n = 0;
  while(copy != 1)
  {
    copy >>= 1;
    n++;
  }
  //printf("n:%d\n", n);
  int current = 4;
  //for(int i = 1; i < n; i++)
  while(current <= cnt)
  {
    answer += a[current - 1];
    current *= 4;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  if(!1)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n");
    printf("64\n");
    for(int i = 0; i < 64; i++)
    {
      printf("1 ");
    }
    return 0;
  }

  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
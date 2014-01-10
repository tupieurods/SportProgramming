#include <stdio.h>
#include <string.h>

using namespace std;

struct query
{
  int l, r;
  __int64 d;
};

int main()
{
  int n, m, k;
  //Read
  scanf("%d %d %d", &n, &m, &k);
  __int64 *a = new __int64[n];
  __int64 *delta = new __int64[n];
  query *q = new query[m];
  __int64 *qq = new __int64[m];
  memset(a, 0, sizeof(__int64) * n);
  memset(delta, 0, sizeof(__int64) * n);
  memset(qq, 0, sizeof(__int64) * m);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &a[i]);
  }
  //Solve
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d %I64d", &q[i].l, &q[i].r, &q[i].d);
    q[i].l--;
  }
  for(int i = 0; i < k; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    qq[x]++;
    if(y != m)
      qq[y]--;
  }
  __int64 sum = 0;
  for(int i = 0; i < m; i++)
  {
    sum += qq[i];
    //printf("debug: %I64d\n", qq[i]);
    delta[q[i].l] += sum * q[i].d;
    if(q[i].r != n)
      delta[q[i].r] -= sum * q[i].d;
  }
  //Write
  sum = 0LL;
  for(int i = 0; i < n; i++)
  {
    sum += delta[i];
    printf("%I64d ", sum + a[i]);
  }
  return 0;
}

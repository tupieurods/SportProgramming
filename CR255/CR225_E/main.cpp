//Time limit solution. Test 9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 1000000009;
__int64 fib[300009];
__int64 a[300009];
int n, m;
int fl[300009 * 4], fr[300009 * 4];
__int64 sum[300009 * 4];

template<int AS>
__int64 getSum(int l, int r)
{
  if(r == 0)
  {
    return 0;
  }
  __int64 result;
  if(AS == 0)
  {
    result = a[r] - a[l - 1];
  }
  if(AS == 1)
  {
    result = fib[r] - fib[l - 1];
  }
  if(result < 0)
  {
    result += MOD;
  }
  return result % MOD;
}

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++)
  {
    scanf("%I64d", &a[i]);
    a[i] = (a[i] + a[i - 1]) % MOD;
  }
}

void printSmall()
{
  printf("fl:\t");
  for(int i = 0; i < 100; i++)
  {
    printf("%d ", fl[i]);
  }
  printf("\nfr:\t");
  for(int i = 0; i < 100; i++)
  {
    printf("%d ", fr[i]);
  }
  printf("\nsum:\t");
  for(int i = 0; i < 100; i++)
  {
    printf("%I64d ", sum[i]);
  }
  printf("\n");
}

void pushDown(int idx, int l, int r)
{
  if(fl[idx] == 0)
  {
    return;
  }
  //printf("pushDown. idx:%d l:%d r:%d\n", idx, l, r);
  //printSmall();
  if(l == r)
  {
    //sum[idx] = (sum[idx] + getSum<1>(fl[idx], fr[idx])) % MOD;
  }
  else
  {
    int mid = (l + r) / 2;
    pushDown(idx * 2 + 1, l, mid);
    pushDown(idx * 2 + 2, mid + 1, r);
    mid = (fl[idx] + fr[idx]) / 2;
    fl[idx * 2 + 1] = fl[idx]; fr[idx * 2 + 1] = mid;
    fl[idx * 2 + 2] = mid + 1; fr[idx * 2 + 2] = fr[idx];
    sum[idx * 2 + 1] = (sum[idx * 2 + 1] + getSum<1>(fl[idx * 2 + 1], fr[idx * 2 + 1])) % MOD;
    sum[idx * 2 + 2] = (sum[idx * 2 + 2] + getSum<1>(fl[idx * 2 + 2], fr[idx * 2 + 2])) % MOD;
    sum[idx] = (sum[idx * 2 + 1] + sum[idx * 2 + 2]) % MOD;
  }
  fl[idx] = fr[idx] = 0;
}

int gl, gr;

void update(int l, int r, int ul, int ur, /*int ufl, int ufr,*/ int idx)
{
  if(ul > ur)
  {
    return;
  }
  //printf("update. l:%d r:%d ul:%d ur:%d idx:%d\n", l, r, ul, ur, idx);
  pushDown(idx, l, r);
  //printSmall();
  if(l == r)//leaf
  {
    sum[idx] = (sum[idx] + getSum<1>(ul - gl + 2, ur - gl + 2)) % MOD;
    return;
  }
  else if(ul == l && ur == r)
  {
    fl[idx] = ul - gl + 2;
    fr[idx] = ur - gl + 2;
    sum[idx] = (sum[idx * 2 + 1] + sum[idx * 2 + 2] + getSum<1>(fl[idx], fr[idx])) % MOD;
    return;
  }
  else
  {
    int mid1 = (l + r) / 2;
    update(l, mid1, ul, min(ur, mid1), idx * 2 + 1);
    update(mid1 + 1, r, max(mid1 + 1, ul), ur, idx * 2 + 2);
  }
  sum[idx] = (sum[idx * 2 + 1] + sum[idx * 2 + 2]) % MOD;
}

__int64 query(int l, int r, int ql, int qr, int idx)
{
  if(ql > qr)
  {
    return 0;
  }
  if(l == r)//leaf
  {
    return sum[idx];
  }
  else if(ql == l && qr == r)
  {
    return sum[idx];
  }
  //printf("query. l:%d r:%d ql:%d qr:%d idx:%d\n", l, r, ql, qr, idx);
  pushDown(idx, l, r);
  //printSmall();
  int mid1 = (l + r) / 2;
  return query(l, mid1, ql, min(qr, mid1), idx * 2 + 1) +
    query(mid1 + 1, r, max(ql, mid1 + 1), qr, idx * 2 + 2);
}

void Solve()
{
  memset(fl, 0, sizeof(fl));
  memset(fr, 0, sizeof(fr));
  memset(sum, 0, sizeof(sum));
  for(int i = 0; i < m; i++)
  {
    int q, l, r;
    scanf("%d %d %d", &q, &l, &r);
    gl = l;
    gr = r;
    l--;
    r--;
    if(q == 1)
    {
      update(0, n - 1, l, r, 0);
    }
    else
    {
      printf("%I64d\n", (query(0, n - 1, l, r, 0) + getSum<0>(l + 1, r + 1)) % MOD);
    }
#ifndef ONLINE_JUDGE
    //printSmall();
    //printf("================================\n");
#endif
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{ 
  fib[0] = 0;
  fib[1] = 1;
  fib[2] = 1;
  for(int i = 3; i < 300009; i++)
  {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }
  for(int i = 2; i < 300009; i++)
  {
    fib[i] = (fib[i] + fib[i - 1]) % MOD;
  }
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
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
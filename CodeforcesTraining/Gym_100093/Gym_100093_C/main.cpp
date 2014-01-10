#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 17;
const int TREESIZE = MAXN * 4;

int n, k;
int arr[TREESIZE];
__int64 arrSum[TREESIZE];

void ReadData()
{
  scanf("%d %d%*c", &n, &k);
}

void push(int index, int cnt)
{
  if(arr[index] != -1)
  {
    arr[index * 2 + 1] = arr[index];
    arr[index * 2 + 2] = arr[index];
    arrSum[index * 2 + 1] = arr[index] * 1LL * cnt;
    arrSum[index * 2 + 2] = arr[index] * 1LL * cnt;
    arr[index] = -1;
  }
}

void update(int index, int ql, int qr, int l, int r, int val)
{
  if(ql > qr)
  {
    return;
  }
  if(ql == l && qr == r)
  {
    arr[index] = val;
    arrSum[index] = val * 1LL * (r - l + 1);
  }
  else
  {
    int cntLocal = (r - l + 1) / 2;
    push(index, cntLocal);
    int newl = l + cntLocal;
    int newr = l + cntLocal - 1;
    update(index * 2 + 1, ql, min(newr, qr), l, newr, val);
    update(index * 2 + 2, max(newl, ql), qr, newl, r, val);
    arrSum[index] = arrSum[index * 2 + 1] + arrSum[index * 2 + 2];
  }
}

void query_A()
{
  int l, r, x;
  scanf("%d %d %d%*c", &l, &r, &x);
  update(0, l, r, 1, MAXN, x);
}

__int64 getSum(int index, int ql, int qr, int l, int r)
{
  if(ql > qr)
  {
    return 0LL;
  }
  if(ql == l && qr == r)
  {
    return arrSum[index];
  }
  int cntLocal = (r - l + 1) / 2;
  push(index, cntLocal);
  int newl = l + cntLocal;
  int newr = l + cntLocal - 1;
  return getSum(index * 2 + 1, ql, min(newr, qr), l, newr)
       + getSum(index * 2 + 2, max(newl, ql), qr, newl, r);
}

void query_Q()
{
  int l, r;
  scanf("%d %d%*c", &l, &r);
  printf("%I64d\n", getSum(0, l, r, 1, MAXN));
}

void Solve()
{
  memset(arr, 0xFF, sizeof(arr));
  memset(arrSum, 0, sizeof(arrSum));
  for(int i = 0; i < k; i++)
  {
    char c;
    scanf("%c", &c);
    if(c == 'A')
    {
      query_A();
    }
    else if(c == 'Q')
    {
      query_Q();
    }
    else
    {
      throw;
    }
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("sum.in", "r", stdin);
  freopen("sum.out", "w", stdout);
  #ifndef ONLINE_JUDGE
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
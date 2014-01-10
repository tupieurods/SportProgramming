#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int n, k, cnt;
__int64 sums[200009];

__int64 getSum(int l, int r)
{
  return sums[r] - sums[l - 1];
}

void ReadData()
{
  scanf("%d %d", &n, &k);
  __int64 sum = 0;
  sums[0] = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    sum += val;
    sums[i + 1] = sum;
  }
  cnt = n - k + 1;
}

int ind1, ind2;

void Solve()
{
  ind1 = n - 2 * k;
  ind2 = n - k;
  __int64 sum = getSum(ind1 + 1, ind1 + k) + getSum(ind2 + 1, ind2 + k);
  __int64 secondMax = getSum(ind2 + 1, ind2 + k);
  int secondMaxIndex = ind2;
  for(int i = ind1 - 1; i >= 0; i--)
  {
    if(getSum(i + k + 1, i + 2 * k) >= secondMax)
    {
      secondMax = getSum(i + k + 1, i + 2 * k);
      secondMaxIndex = i + k;
    }
    if(getSum(i + 1, i + k) + secondMax >= sum)
    {
      sum = getSum(i + 1, i + k) + secondMax;
      ind1 = i;
      ind2 = secondMaxIndex;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", ind1 + 1, ind2 + 1);
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
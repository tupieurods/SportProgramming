#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[500009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

__int64 answer;
__int64 sums[500009];
vector<__int64> v;

void Solve()
{
  answer = 0;
  if(n < 3)
  {
    return;
  }
  memset(sums, 0, sizeof(sums));
  for(int i = 1; i <= n; i++)
  {
    sums[i] = sums[i - 1] + a[i - 1];
  }
  if(sums[n] % 3 != 0)
  {
    return;
  }
  __int64 d = (sums[n] / 3LL) * 2LL;
  v.clear();
  for(int i = 1; i <= n; i++)
  {
    if(sums[i] == d)
    {
      v.push_back(i);
    }
  }
  __int64 d0 = sums[n] / 3LL;
  vector<__int64>::iterator it;
  for(int i = 1; i <= n; i++)
  {
    if(sums[i] == d0)
    {
      it = upper_bound(v.begin(), v.end(), i);
      if(it != v.end())
      {
        int idx = it - v.begin();
        int add = v.size() - idx;
        if(v[v.size() - 1] == n)
        {
          add--;
        }
        answer += add;
      }
    }
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
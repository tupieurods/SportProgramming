#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

struct wtf
{
  int a, b, index;
};

int n, p, k;
wtf a[100009];

void ReadData()
{
  scanf("%d %d %d", &n, &p, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &a[i].a, &a[i].b);
    a[i].index = i + 1;
  }
}

int compare(const void *v1, const void *v2)
{
  wtf val1 = *(wtf*)v1;
  wtf val2 = *(wtf*)v2;
  if(val1.b == val2.b)
  {
    return val2.a - val1.a;
  }
  return val1.b - val2.b;
}

int compare2(const void *v1, const void *v2)
{
  wtf val1 = *(wtf*)v1;
  wtf val2 = *(wtf*)v2;
  return val2.a - val1.a;
}

__int64 prefixSum[100009];
int answerPos;
pair<__int64, __int64> result;

__int64 getSum(int l, int r)
{
  return prefixSum[r + 1] - prefixSum[l];
}

void Solve()
{
  qsort(a, n, sizeof(wtf), compare);
  multiset<int> vals;
  prefixSum[0] = 0;
  prefixSum[1] = a[0].b;
  for(int i = 1; i < n; i++)
  {
    prefixSum[i + 1] = prefixSum[i] + a[i].b;
  }
  __int64 sum = 0;
  for(int i = 0; i < k - 1; i++)
  {
    sum += a[n - 1 - i].a;
    vals.insert(a[n - 1 - i].a);
  }
  result = make_pair(-1, -1);
  answerPos = -1;
  for(int i = n - k; i >= p - k; i--)
  {
    __int64 bSum = 0;
    if(p != k)
    {
      bSum = getSum(i - p + k, i - 1);
    }
    pair<__int64, __int64> current = make_pair(sum + a[i].a, bSum);
    if(current > result)
    {
      answerPos = i;
      result = current;
    }
    sum += a[i].a;
    vals.insert(a[i].a);
    sum -= *vals.begin();
    vals.erase(vals.begin());
  }
}

void WriteData()
{
  #ifndef ONLINE_JUDGE
    printf("%I64d %I64d\n", result.first, result.second);
  #endif
  qsort(a + answerPos, n - answerPos, sizeof(wtf), compare2);
  for(int i = 0; i < p; i++)
  {
    if(answerPos - p + k + i < 0 || answerPos - p + k - 1 + i >= n)
      throw;
    printf("%d ", a[answerPos - p + k + i].index);
  }
  printf("\n");
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
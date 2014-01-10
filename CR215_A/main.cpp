#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n, d;
    scanf("%d %d", &n, &d);
    int sum = 0;
    int sums[109];
    std::vector<int> v;
    for(int i = 0; i < n; i++)
    {
      int val;
      scanf("%d", &val);
      v.push_back(val);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
      sum += v[i];
      sums[i] = sum;
    }
    int m;
    scanf("%d", &m);
    if(m > n)
    {
      sum -= (m - n) * d;
    }
    else
    {
      sum = sums[m - 1];
    }
    printf("%d\n", sum);
  }
  return 0;
}
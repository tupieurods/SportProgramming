#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;

bool comparer(pair<int, int> a, pair<int, int> b)
{
  if(a.first == b.first)
    return a.second > b.second;
  return a.first > b.first;
}

inline __int64 max(__int64 a, __int64 b)
{
  return a > b ? a : b;
}

int main()
{
  pair<int, int> a[3];
  while(true)
  {
    int cntZero = 0;
    for(int i = 0; i < 3; i++)
    {
      scanf("%d %d", &a[i].first, &a[i].second);
      if(a[i].first == 0) cntZero++;
      if(a[i].second == 0) cntZero++;
      if(a[i].second > a[i].first) swap(a[i].first, a[i].second);
    }
    if(cntZero == 6)
      break;
    __int64 answer = 0LL;
    sort(a, a + 3, comparer);
    answer = (__int64)a[0].first * a[0].second;
    __int64 h = a[0].second, w = a[0].first;
    for(int i = 1; i < 3; i++)
    {
      __int64 delta = a[i].second - h;
      if(delta > 0)
      {
        answer += (__int64)a[i].first * delta;
      }
      h = max(h, a[i].second);
    }
    printf("%I64d\n", answer);
  }
  return 0;
}
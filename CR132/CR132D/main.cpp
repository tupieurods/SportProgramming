#include <stdio.h>

using namespace std;

#define INT64_MAX   0x7fffffffffffffffLL

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  __int64 count = 0;
  __int64 first;
  __int64 second;
  for(int i = 0; i < n; i++)
    {
      first = INT64_MAX;
      second = INT64_MAX;
      int t, tcritical, penalty, cost;
      scanf("%d %d %d %d", &t, &tcritical, &penalty, &cost);
      //Все едут в одном автобусе
      first = cost + (t + m > tcritical ? (__int64)m * penalty : 0);
      int tmp = tcritical - t; //Столько уместится в одном автобусе без штрафов
      second = tmp <= 0 ? first : (m / tmp + ( m % tmp == 0 ? 0 : 1)) * (__int64)cost;
      count += first < second ? first : second;
    }
  printf("%I64d", count);
  return 0;
}

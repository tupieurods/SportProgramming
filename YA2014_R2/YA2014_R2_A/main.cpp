#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define INT64 "%I64d"
#else
#define INT64 "%lld"
#endif

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define UNS64 "%I64u"
#else
#define UNS64 "%llu"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main()
{
  int n, k, c;
  long long answer = 0;
  scanf("%d %d", &n, &k);
  int a[100009];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  std::sort(a, a + n);
  for(int i = n - 1; i >= 0; i--)
  {
    int t = i == n - 1 ? a[i] - (k - 2) : a[i] - (k - 2) * 2;
    if(t <= 0)
    {
      continue;
    }
    else
    {
      answer += 1 + (t - 1) / k;
    }
  }
  printf(INT64 "\n", answer);
  return 0;
}
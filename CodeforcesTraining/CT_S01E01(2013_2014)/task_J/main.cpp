#include <stdio.h>
#include <stdlib.h>

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  int n, k;
  while(scanf("%d %d", &n, &k) != EOF)
  {
    int answer = n;
    int m = 0;
    while(n >= k)
    {
      m = n / k;
      answer += m;
      n = n % k + m;
    }
    printf("%d\n", answer);
  }
  return 0;
}
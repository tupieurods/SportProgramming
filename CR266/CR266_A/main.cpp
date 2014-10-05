#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int n, m, a, b;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int answer = 0;
    if(a * m < b)
    {
      answer = n * a;
    }
    else
    {
      answer = (n / m) * b;
      int last = n % m;
      if(last > 0)
      {
        answer += b < last * a ? b : last * a;
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}
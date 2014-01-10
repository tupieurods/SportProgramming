#include <stdio.h>
#include <stdlib.h>

inline int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d", &n);
    int lastTime = 0;
    int q = 0;
    scanf("%d %d", &lastTime, &q);
    int maxTime = lastTime, maxQ = q;
    for(int i = 1; i < n; i++)
    {
      int t, c;
      scanf("%d %d", &t, &c);
      int delta = t - lastTime;
      if(delta >= q)
      {
        q = c;
      }
      else
      {
        q = q - delta + c;
      }
      maxTime = t;
      lastTime = t;
      maxQ = max(maxQ, q);
    }
    maxTime = maxTime + q;
    printf("%d %d\n", maxTime, maxQ);
  }
  return 0;
}
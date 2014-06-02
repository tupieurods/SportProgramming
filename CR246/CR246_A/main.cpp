#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  //int a[7];
  for(int T = 0; T < QWE; T++)
  {
    int n, k;
    scanf("%d %d", &n, &k);
    //memset(a, 0, sizeof(a));
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
      int val;
      scanf("%d", &val);
      if(5 - val >= k)
      {
        answer++;
      }
    }
    printf("%d\n", answer / 3);
  }
  return 0;
}
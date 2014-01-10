#include <stdio.h>
#include <stdlib.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d", &n);
    int answer = 1;
    int prev;
    scanf("%d", &prev);
    for(int i = 1; i < n; i++)
    {
      int current;
      scanf("%d", &current);
      if(prev != current)
      {
        answer++;
      }
      prev = current;
    }
    printf("%d\n", answer);
  }
  return 0;
}
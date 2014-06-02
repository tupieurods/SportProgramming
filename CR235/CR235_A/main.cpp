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
    int n, xVal;
    scanf("%d %d", &n, &xVal);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      int current;
      scanf("%d", &current);
      sum += current;
    }
    sum = sum < 0 ? -sum : sum;
    int answer = sum / xVal;
    printf("%d\n", answer + ((sum % xVal) == 0 ? 0 : 1));
  }
  return 0;
}
#include <stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  if(n / k < 3)
  {
    printf("-1");
    return 0;
  }
  int current = 1;
  for(; current <= k; current++)
  {
    printf("%d ", current);
  }
  for(int i = 1; i <= k; i++)
  {
    printf("%d %d ", i, i);
    current += 2;
  }
  for(; current <= n; current++)
  {
    printf("%d ", 1);
  }
  return 0;
}

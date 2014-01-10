#include <stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int current = n;
  for(int i = 0; i < k; i++)
  {
    printf("%d ", current);
    current--;
  }
  n -= k;
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", i);
  }
  return 0;
}

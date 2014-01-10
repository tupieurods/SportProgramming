#include <stdio.h>

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  if(k > n)
    n = k;
  n *= 2;
  int answer = n / k + (n % k != 0);
  printf("%d\n", answer);
  return 0;
}
#include <stdio.h>

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int main()
{
  int n;
  scanf("%d", &n);
  int last = n % 10;
  int answer = max(n, max(n / 10, (n / 100) * 10 + last));
  printf("%d", answer);
  return 0;
}
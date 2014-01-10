#include <stdio.h>

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int main()
{
  int n, k;
  scanf("%d %d", &k, &n);
  int answer = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    answer = max(0, answer + val - k);
  }
  printf("%d\n", answer);
  return 0;
}
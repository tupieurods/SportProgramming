#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int n;
  scanf("%d", &n);
  int answer = n - 1;
  int cnt = 0;
  int a = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a += val;
  }
  if(a % n == 0)
  {
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}
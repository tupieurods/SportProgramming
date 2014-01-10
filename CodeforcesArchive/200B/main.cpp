#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);
  double answer = 0.0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    answer += val;
  }
  printf("%.10lf\n", answer / n);
  return 0;
}
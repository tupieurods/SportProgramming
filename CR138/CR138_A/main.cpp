#include <stdio.h>
#include <math.h>

int main()
{ 
  int s1, s2, s3;
  scanf("%d %d %d", &s1, &s2, &s3);
  int a = (int)sqrt((double)(s1 * s3) / s2);
  int b = s1 / a;
  int c = s3 / a;
  printf("%d\n", 4 * (a + b + c));
  return 0;
}
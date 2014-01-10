#include <stdio.h>

using namespace std;

int main()
{
  int n, a, b, c;
  scanf("%d", &n);
  scanf("%d %d %d", &a, &b, &c);
  int sum = a + b + c;
  int center = 2;
  for(int i = 1; i <= n - 3; i++)
  {
    a = b;
    b = c;
    scanf("%d", &c);
    if(a+b+c>sum)
    {
      sum=a+b+c;
      center=2+i;
    }
  }
  printf("%d %d", sum, center);
  return 0;
}

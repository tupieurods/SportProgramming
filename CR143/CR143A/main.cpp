#include <stdio.h>

using namespace std;

int main()
{
  int n, a, b, c;
  scanf("%d", &n);
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &a, &b, &c);
    if(a + b + c >= 2)
      result++;
  }
  printf("%d", result);
  return 0;
}

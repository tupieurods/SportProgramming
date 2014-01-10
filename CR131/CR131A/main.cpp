#include <stdio.h>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int count = 0;
  int a = 0, b = 0;
  int tmp;
  do
    {
      tmp = a * a;
      if(tmp <= n)
        {
          b = n - tmp;
          if(b*b + a == m)
            count++;
        }
      else
        break;
      a++;
    }
  while(true);
  printf("%d", count);
  return 0;
}

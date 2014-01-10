#include <stdio.h>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int x = 0, y = 0;
  if((m == 3 && n == 6) || (m == 3 && n == 5))
  {
    printf("-1");
    return 0;
  }
  for(int i = 0; i < m; i++)
  {
    x++;
    y = (x * x) + 10000000;
    printf("%d %d\n", x, y);
  }
  int delta = n - m;
  x = 1;
  for(int i = 0; i < delta; i++)
  {
    x++;
    y = -(x * x) - 10000000;
    printf("%d %d\n", x, y);
  }
  return 0;
}

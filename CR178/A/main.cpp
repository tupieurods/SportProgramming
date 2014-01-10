#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int *a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    int l = y - 1, r = a[x] - l - 1;
    if(x != 0)
    {
      a[x - 1] += l;
    }
    if(x != n - 1)
    {
      a[x + 1] += r;
    }
    a[x] = 0;
  }
  for(int i = 0; i < n; i++)
  {
    printf("%d\n", a[i]);
  }
  return 0;
}

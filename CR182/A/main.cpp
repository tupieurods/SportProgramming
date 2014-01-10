#include <stdio.h>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int a = 0, b = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(tmp > 0)
      a++;
    else
      b++;
  }
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    int delta = r - l + 1;
    int d1 = delta / 2;
    int d2 = delta - d1;
    if(d1 <= a && d2 <= b && d1 - d2 == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}

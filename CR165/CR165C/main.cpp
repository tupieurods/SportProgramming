#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int p = -1;
  for(int i = 0; i < n; i++)
  {
    int k, a;
    scanf("%d %d", &k, &a);
    int current = k + (int)ceil((log((double)a) / log(4.0)));
    if(current == k)
      current++;
    p = max(current, p);
  }
  printf("%d\n", p);
  return 0;
}

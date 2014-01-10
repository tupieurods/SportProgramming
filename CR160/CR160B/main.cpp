#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d\n", &n, &k);
  int absSmallest = INT_MAX;
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if((k != 0) && (tmp <= 0))
    {
      sum += abs(tmp);
      k--;
    }
    else
      sum += tmp;
    absSmallest = min(absSmallest, abs(tmp));
  }
  if(k != 0)
  {
    if(k % 2 == 1)
      sum -= 2 * absSmallest;
  }
  printf("%d", sum);
  return 0;
}

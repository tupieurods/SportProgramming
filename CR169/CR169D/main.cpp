#include <stdio.h>
#include <limits.h>

using namespace std;

int main()
{
  __int64 l, r;
  scanf("%I64d %I64d", &l, &r);
  l = l ^ r;
  r = 1LL;
  while(r <= l)
  {
    r <<= 1LL;
  }
  r--;
  printf("%I64d", r);
  return 0;
}

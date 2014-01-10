#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  __int64* steps = new __int64[n];
  //__int64 current = 0;
  for(int i =0; i < n; i++)
  {
    __int64 tmp;
    //scanf("%I64d", &tmp);
    scanf("%I64d", &steps[i]);
    //current += tmp;
    //steps[i] = tmp;
    //printf("steps[%d]=%I64d", i, steps[i]);
  }
  int m;
  scanf("%d", &m);
  __int64 currentH = steps[0];
  for(int i = 0; i < m; i++)
  {
    __int64 w, h;
    scanf("%I64d %I64d", &w, &h);
    //printf("before: %I64d\n", currentH);
    if(currentH < steps[w - 1])
      currentH = steps[w - 1];
    //printf("after: %I64d\n", currentH);
    printf("%I64d\n", currentH);
    currentH += h;
  }
  return 0;
}

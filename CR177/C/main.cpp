#include <stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  if(k > n)
  {
    printf("-1");
    return 0;
  }
  if(k == 1)
  {
    if(n > 1)
    {
      printf("-1");
    }
    else
    {
      printf("a");
    }
    return 0;
  }
  int last = k - 2;
  int currN = n - last;
  for(int i = 1; i <= currN; i++)
  {
    if(i % 2 == 1)
    {
      printf("a");
    }
    else
    {
      printf("b");
    }
  }
  for(int i = 0; i < last; i++)
  {
    printf("%c", 'a' + 2 + i);
  }
  return 0;
}

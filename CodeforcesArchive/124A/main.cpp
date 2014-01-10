#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, n;
  scanf("%d %d %d", &n, &a, &b);
  int answer = 0;
  for(int i = 1; i <= n; i++)
  {
    if(i >= a + 1 && i >= n - b)
    {
      answer++;
    }
  }
  printf("%d\n", answer);
  return 0;
}
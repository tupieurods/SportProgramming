#include <stdio.h>
#include <limits.h>

using namespace std;

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int answer = INT_MAX;
  int *a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    answer = min(answer, a[i]);
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i] % answer != 0)
    {
      answer = -1;
      break;
    }
  }
  printf("%d", answer);
  return 0;
}

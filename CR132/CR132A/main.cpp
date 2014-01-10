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
  int bred[10000];
  for(int i = 0; i < 10000; i++)
    bred[i] = 0;
  for(int i = 0; i < m; i++)
    {
      int b;
      scanf("%d", &b);
      for(int j = 0; j < n; j++)
        {
          if(b % a[j] != 0)
            continue;
          bred[b/a[j]]++;
        }
    }
  for(int i = 9999; i >= 0; i--)
    {
      if(bred[i] != 0)
        {
          printf("%d", bred[i]);
          break;
        }
    }
  return 0;
}

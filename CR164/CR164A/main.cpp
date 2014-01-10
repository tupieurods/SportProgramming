#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int* a = new int[n];
  int* b = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &a[i], &b[i]);
  }
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j)
        continue;
      if(a[i] == b[j])
        count++;
    }
  }
  printf("%d\n", count);
  return 0;
}

#include <stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int *a = new int[n];
  k--;
  int value;
  bool flag = true;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    if(i == k)
    {
      value = a[i];
    }
    else if(i > k)
    {
      flag = a[i] == value;
    }
    if(!flag)
      break;
  }
  if(flag)
  {
    int pos = k;
    while(pos >= 0 && a[pos] == a[k])
      pos--;
    printf("%d\n", pos + 1);
    return 0;
  }
  printf("-1\n");
  return 0;
}

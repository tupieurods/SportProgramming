#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  if(n == 1)
  {
    printf("1");
    return 0;
  }
  if(((n % 4) == 2) || ((n % 4) == 3))
  {
    printf("-1");
    return 0;
  }
  int* data = new int[n + 1];
  memset(data, 0, sizeof(int) * (n + 1));
  int count = n % 2 == 0 ? n / 2 : (n - 1) / 2;
  if((n % 2) != 0)
    data[count + 1] = count + 1;
  for(int i = 1; i < count; i += 2)
  {
    data[i] = i + 1;
    int ind = i;
    do
    {
      data[data[ind]] = n - ind + 1;
      ind = data[ind];
    }while(ind != i);
  }
  for(int i = 1; i <= n; i++)
  {
    printf("%d ", data[i]);
  }
  return 0;
}

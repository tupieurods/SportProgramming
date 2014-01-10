#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int* array = new int[n+1];
  int inData;
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &inData);
    array[inData] = i;
  }
  __int64 first = 0;
  __int64 second = 0;
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++)
  {
    scanf("%d", &inData);
    first += array[inData];
    second += n - array[inData] + 1;
  }
  printf("%I64d %I64d", first, second);
  return 0;
}

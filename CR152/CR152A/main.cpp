#include <stdio.h>
#include <stdlib.h>

using namespace std;

int inline min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int n;
  scanf("%d", &n);
  int sumLeft = 0;
  int sumRight = 0;
  for(int i = 0; i < n; i++)
  {
    int left, right;
    scanf("%d %d", &left, &right);
    sumLeft += left;
    sumRight += right;
  }
  printf("%d", min(sumLeft + (n - sumRight), (n - sumLeft) + sumRight));
  return 0;
}

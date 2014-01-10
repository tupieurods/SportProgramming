#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(int* arr, int l, int r)
{
  return arr[r] - arr[l - 1];
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int* data = new int[n];
  int* up = new int[n];
  int* down = new int[n];
  int* eq = new int[n + 1];
  memset(eq, 0, sizeof(int) * (n + 1));
  up[0] = 0;
  down[0] = 0;
  scanf("%d", &data[0]);
  for(int i = 1; i < n; i++)
  {
    scanf("%d", &data[i]);
    if(data[i] >= data[i - 1])
    {
      up[i] = up[i - 1];
    }
    else
    {
      up[i] = i;
    }
    if(data[i] <= data[i - 1])
    {
      down[i] = down[i - 1];
    }
    else
    {
      down[i] = i;
    }
  }
  for(int i = 2; i < n; i++)
  {
  }
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    if((up[down[r]] == up[l]) || (down[l] == down[r]))
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
  }
  return 0;
}

#include <stdio.h>
#include <vector>

int main()
{
  int n;
  scanf("%d", &n);
  int *arr = new int[n + 1];
  arr[n] = 1000;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  int index = 1;
  std::vector<std::pair<int, int>> v;
  int counter = 1;
  for(int i = 0; i < n; i++)
  {
    if(arr[i] == arr[i + 1])
    {
      counter++;
    }
    else
    {
      printf("%d %d ", counter, arr[i]);
      counter = 1;
    }
  }
  return 0;
}
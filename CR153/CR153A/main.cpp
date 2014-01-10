#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int* data = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &data[i]);
  }
  int max = 0;
  for(int i = 0; i < n; i++)
  {
    int currentMax = 0;
    for(int j = i; j < n; j++)
    {
      currentMax = currentMax ^ data[j];
      if(currentMax > max)
        max = currentMax;
    }
  }
  printf("%d", max);
  return 0;
}

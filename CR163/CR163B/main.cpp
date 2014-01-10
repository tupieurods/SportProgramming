#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, t;
  scanf("%d %d\n", &n, &t);
  char* data = new char[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%c", &data[i]);
  }
  for(int i = 0; i < t; i++)
  {
    for(int j = 0; j < n;)
    {
      if(j == n - 1)
      {
        j++;
        continue;
      }
      if(data[j] == 'B' && data[j + 1] == 'G')
      {
        swap(data[j], data[j + 1]);
        j += 2;
      }
      else
      {
        j++;
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    printf("%c", data[i]);
  }
  return 0;
}

#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  if(n <= 2)
  {
    printf("-1\n");
    return 0;
  }
  bool AllSameSize = true;
  bool toRight = true;
  bool toLeft = true;
  int* data = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &data[i]);
    if(i > 0)
    {
      if(data[i] >= data[i - 1])
        toRight = false;
      else
        toLeft = false;
      if(data[i] != data[i - 1])
        AllSameSize = false;
    }
  }
  if(AllSameSize)
  {
    printf("-1\n");
    return 0;
  }
  if(toRight || toLeft)
  {
    printf("%d %d\n", 1, n);
    return 0;
  }
  int first = 0;
  int second = n - 1;
  for(int i = n - 1; i > 0; i--)
  {
    if(data[0] == data[i])
      continue;
    if((((i != n - 1) && (data[first] > data[i + 1])) && (data[first] < data[i - 1]) && (data[i] < data[1]))
        || (((i != n - 1) && (data[first] < data[i + 1])) && (data[first] > data[i - 1]) && (data[i] > data[1])))
    {
      second = i;
      break;
    }
    //second--;
  }
  printf("%d %d\n", first + 1, second + 1);
  return 0;
}

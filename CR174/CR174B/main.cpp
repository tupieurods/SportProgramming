#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  char* str = new char[n + 10];
  scanf("%s", str);
  int arr[3] = {0, 0, 0};
  for(int i = 0; i < n; i++)
  {
    if(str[i] == 'A')
    {
      arr[0]++;
    }
    if(str[i] == 'F')
    {
      arr[1]++;
    }
    if(str[i] == 'I')
    {
      arr[2]++;
    }
  }
  if(arr[2] == 0)
  {
    printf("%d\n", arr[0]);
  }
  else if(arr[2] == 1)
  {
    printf("1");
  }
  else
  {
    printf("0");
  }
  return 0;
}

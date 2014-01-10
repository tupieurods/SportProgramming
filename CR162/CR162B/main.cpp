#include <stdio.h>

using namespace std;

int abs(int value)
{
  return value > 0 ? value : -value;
}

int main()
{
  int n;
  scanf("%d", &n);
  int result = 0;
  int prev = 0;
  for(int i = 0; i < n; i++)
  {
    int current;
    scanf("%d", &current);
    result += abs(current - prev);
    if(i != 0)
      result++;
    prev = current;
  }
  printf("%d", result + n);
  return 0;
}

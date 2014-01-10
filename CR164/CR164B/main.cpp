#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int count = n;
  int pressed = 1;
  int current = n - 1;
  for(int i = 1; i < n; i++)
  {
    count += (current - 1) * (pressed + 1) + 1;
    pressed++;
    current--;
  }
  printf("%d\n", count);
  return 0;
}

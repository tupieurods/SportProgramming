#include <stdio.h>

using namespace std;

int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d", b * c + (b + c - 1)*(a - 1));
  return 0;
}

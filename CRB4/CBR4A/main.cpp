#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  printf("%s", n % 2 == 0 && n!=2 ? "YES" : "NO");
}

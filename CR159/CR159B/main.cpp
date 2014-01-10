#include <stdio.h>
#include <stdlib.h>

using namespace std;

int min(int a, int b)
{
  return a > b ? b : a;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int first = abs(m - n);
  int minimal = min(m, n);
  int second = minimal;
  first += minimal - 1;
  printf("%d %d", first, second);
  return 0;
}

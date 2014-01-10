#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  int answer = n * (m / 2) + (m % 2) * (n / 2);
  answer = max(answer, m * (n / 2) + (n % 2) * (m / 2));
  printf("%d\n", answer);
  return 0;
}
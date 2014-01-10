#include <stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    sum += r - l + 1;
  }
  int answer = 0;
  if(sum % k != 0)
  {
    answer = k - sum % k;
  }
  printf("%d", answer);
  return 0;
}

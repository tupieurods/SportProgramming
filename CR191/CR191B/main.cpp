#include <stdio.h>
#include <set>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n;
  scanf("%d", &n);
  for(int i = 10000000 - n + 1; i <= 10000000; i++)
  {
    printf("%d ", i);
  }
  return 0;
}
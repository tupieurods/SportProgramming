#include <stdio.h>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  int answer = INT_MIN;
  for(int i = 0; i < n; i++)
  {
    int f, t;
    scanf("%d %d", &f, &t);
    if(t <= k)
    {
      answer = max(answer, f);
    }
    else
    {
      answer = max(answer, f - (t - k));
    }
  }
  printf("%d\n", answer);
  return 0;
}

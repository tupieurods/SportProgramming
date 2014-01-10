#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  std::pair<int, int> a[2009];
  if(n <= 3)
  {
    printf("no\n");
    return 0;
  }
  scanf("%d %d", &a[0].first, &a[0].second);
  int prev = a[0].second;
  if(a[0].first > a[0].second)
  {
    swap(a[0].first, a[0].second);
  }
  for(int i = 2; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a[i - 1].first = prev;
    a[i - 1].second = val;
    if(a[i - 1].first > a[i - 1].second)
    {
      swap(a[i - 1].first, a[i - 1].second);
    }
    for(int j = 0; j < i - 1; j++)
    {
      int sum = 0;
      bool c1 = a[i - 1].first < a[j].first && a[i - 1].second > a[j].first && a[i - 1].second < a[j].second;
      bool c2 = a[i - 1].first > a[j].first && a[i - 1].first < a[j].second && a[i - 1].second > a[j].second;
      if(c1 || c2)
      {
        printf("yes\n");
        return 0;
      }
    }
    prev = val;
  }
  printf("no\n");
  return 0;
}
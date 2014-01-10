#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  deque<int> d1, d2;
  for(int i = 0; i < n; i++)
  {
    int t, w;
    scanf("%d %d", &t, &w);
    if(t == 1)
      d1.push_back(w);
    else
      d2.push_back(w);
  }
  int answer = 1000000;
  sort(d1.begin(), d1.end());
  sort(d2.begin(), d2.end());
  int d1s = d1.size(), d2s = d2.size();
  int l1 = 0, l2;
  for(int i = 0; i <= d1s; i++)
  {
    l2 = 0;
    for(int j = 0; j <= d2s; j++)
    {
      if((d1s - i + (d2s - j) * 2) >= l1 + l2)
        answer = min(answer, d1s - i + (d2s - j) * 2);
      if(j < d2s)
        l2 += d2[j];
    }
    if(i < d1s)
        l1 += d1[i];
  }
  printf("%d", answer);
  return 0;
}

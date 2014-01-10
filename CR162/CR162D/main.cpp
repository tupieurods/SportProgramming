#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int gcd(int p, int q)
{
  if(p == 0)
    return q;
  return (q, p % q);
}

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> data;
  data.reserve(n);
  vector<int> dynamic;
  dynamic.reserve(n);
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    data.push_back(tmp);
    dynamic.push_back(INT_MAX);
  }
  dynamic[0] = INT_MIN;
  dynamic.push_back(INT_MAX);
  for(int i = 0; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(gcd(dynamic[j], data[i])>1)
        dynamic[j] = data[i];
    }
  }
  int maximal = INT_MIN;
  for(int i = 0; i <= n; i++)
  {
    printf("%d\n", dynamic[i]);
    //maximal = max(maximal, dynamic[i]);
  }
  //printf("%d", maximal);
  return 0;
}

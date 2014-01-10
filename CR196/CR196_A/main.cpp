#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> v;
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    v.push_back(val);
  }
  sort(v.begin(), v.end());
  int answer = 2000;
  for(int i = 0; i < m - n + 1; i++)
  {
    answer = min(answer, v[i + n - 1] - v[i]);
  }
  printf("%d\n", answer);
}
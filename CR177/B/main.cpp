#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  vector<int> v;
  int failNum = -1;
  int cnt = n * m;
  for(int i = 0; i < cnt; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    v.push_back(tmp);
    if((failNum == -1) || (tmp % d == failNum))
    {
      failNum = tmp % d;
    }
    else
    {
      printf("-1");
      return 0;
    }
  }
  sort(v.begin(), v.end());
  int index = cnt / 2;
  int answer = 0;
  for(int i = 0; i < cnt; i++)
  {
    if(i != index)
    {
      answer += abs(v[i] - v[index]) / d;
    }
  }
  printf("%d", answer);
  return 0;
}

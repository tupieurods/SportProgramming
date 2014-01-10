#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> answer;
  for(int j = 0; j < m; j++)
  {
    answer.push_back(make_pair(1, j + 1));
  }
  for(int i = 1; i < n; i++)
  {
    answer.push_back(make_pair(i + 1, 1));
  }
  int len = answer.size();
  printf("%d\n", len);
  for(int i = 0; i < len; i++)
  {
    printf("%d %d\n", answer[i].first, answer[i].second);
  }
  return 0;
}
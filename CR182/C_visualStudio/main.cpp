#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
bool used[205];
int zero, pos, neg, cnt, n, answer;

inline int max(int a, int b)
{
  return a > b ? a : b;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

void dfs(int current)
{
  used[current] = true;
  answer = min(answer, current);
  int positive = cnt - zero - current;
  for(int i = 0; i <= min(n, zero); i++)
  {
    int maximal = min(current, n - i);
    for(int j = 0; j <= maximal; j++)
    {
      int k = n - i - j;
      if(k <= positive)
      {
        int nextVal = current - j + k;
        if(!used[nextVal])
          dfs(nextVal);
      }
    }
  }
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    v.clear();
    scanf("%d", &n);
    cnt = 2 * n - 1;
    zero = 0, pos = 0, neg = 0;
    for(int i = 0; i < cnt; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      if(tmp == 0)
        zero++;
      else if(tmp > 0)
        pos++;
      else
        neg++;
      if(tmp != 0)
        v.push_back(abs(tmp));
    }
    sort(v.begin(), v.end());
    memset(used, 0, sizeof(used));
    answer = 100000;
    dfs(neg);
    //printf("%d\n", answer);
    int result = 0;
    for(int i = 0; i < v.size(); i++)
    {
      if(i < answer)
        result -= v[i];
      else
        result += v[i];
    }
    printf("%d\n", result);
  }
  return 0;
}

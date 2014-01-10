#include <cstdio>
#include <cstdlib>
#include <deque>
#include <algorithm>

using namespace std;

int* inData;
int n;

int solve()
{
  deque<int> d;
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    while(!d.empty() && d[0] < inData[i])
    {
      d.erase(d.begin());
    }
    d.push_front(inData[i]);
    if(d.size() > 1)
    {
      result = max(result, d[0] ^ d[1]);
    }
  }
  return result;
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
    scanf("%d", &n);
    inData = new int[n];
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &inData[i]);
    }
    int answer = solve();
    reverse(inData, inData + n);
    answer = max(answer, solve());
    printf("%d\n", answer);
  }
  return 0;
}
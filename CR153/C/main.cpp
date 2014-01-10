#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int n, d;
__int64 answer;
vector<pair<int, int>> a;

void ReadData()
{
  scanf("%d %d", &n, &d);
  int pos = 0;
  a.clear();
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    while(pos != a.size() && abs(a[pos].second - tmp) > d)
    {
      pos++;
    }
    a.push_back(make_pair(pos, tmp));
  }
}

void Solve()
{
  answer = 0LL;
  for(int i = n - 1; i > 1; i--)
  {
    __int64 k = i - a[i].first;
    answer += (k * (k - 1)) / 2LL;
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
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
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
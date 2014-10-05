#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> edges[1009];
pair<int, int> a[1009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 1009; i++)
  {
    edges[i].clear();
  }
  #endif
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    from--;
    to--;
    edges[from].push_back(to);
    edges[to].push_back(from);
  }
}

__int64 answer;
bool used[1009];
int remap[1009];

void Solve()
{
  answer = 0;
  sort(a, a + n);
  memset(used, 0, sizeof(used));
  for(int i = 0; i < n; i++)
  {
    remap[a[i].second] = i;
  }
  for(int i = n - 1; i >= 0; i--)
  {
    used[a[i].second] = true;
    for(vector<int>::iterator it = edges[a[i].second].begin(); it != edges[a[i].second].end(); ++it)
    {
      if(!used[*it])
      {
        answer += a[remap[*it]].first;
      }
    }
  }
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
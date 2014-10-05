#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
pair<int, int> a[100009];
vector<int> edges[100009];
int p[100009], Rank[100009], sz[100009];

int findSet(int idx)
{
  if(p[idx] != idx)
  {
    p[idx] = findSet(p[idx]);
  }
  return p[idx];
}

void link(int idx1, int idx2)
{
  if(Rank[idx1] > Rank[idx2])
  {
    p[idx2] = idx1;
    sz[idx1] += sz[idx2];
  }
  else
  {
    p[idx1] = idx2;
    sz[idx2] += sz[idx1];
  }
  if(Rank[idx1] == Rank[idx2])
  {
    Rank[idx2]++;
  }
}

void unionSet(int idx1, int idx2)
{
  int s1 = findSet(idx1);
  int s2 = findSet(idx2);
  if(s1 != s2)
  {
    link(s1, s2);
  }
}

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i].first);
    a[i].second = i;
    p[i] = i;
    sz[i] = 1;
  }
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 100009; i++)
  {
    edges[i].clear();
  }
  #endif
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

double answer;
bool used[100009];

void Solve()
{
  answer = 0;
  memset(Rank, 0, sizeof(Rank));
  memset(used, 0, sizeof(used));
  int cs = 0;
  sort(a, a + n);
  vector<int> current;
  for(int i = n - 1; i >= 0; i--)
  {
    int idx = a[i].second;
    used[idx] = true;
    current.clear();
    for(vector<int>::iterator it = edges[idx].begin(); it != edges[idx].end(); ++it)
    {
      if(used[*it])
      {
        current.push_back(*it);
      }
    }
    if(current.size() == 0)
    {
      continue;
    }
    vector<int>::iterator it = current.begin();
    int f = *it;
    int s1, s2, sIdx;
    ++it;
    for(; it != current.end(); ++it)
    {
      s1 = findSet(f);
      s2 = findSet(*it);
      sIdx = findSet(idx);
      if(s1 != s2)
      {
        answer += a[i].first * 1.0 * sz[s1] * sz[s2];
        unionSet(s1, s2);
      }
    }
    s1 = findSet(f);
    s2 = findSet(idx);
    if(s1 != s2)
    {
      answer += a[i].first * 1.0 * sz[s1] * sz[s2];
      unionSet(s1, s2);
    }
  }
}

void WriteData()
{
  printf("%lf\n", (answer * 2.0)/ (n * (n - 1.0)));
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> edges[100009];
bool solo[100009];
int p[100009], r[100009];
int packs[100009];
int packCnt;
pair<int, int> ask[100009];
int askCnt;

vector<pair<int, int>> q;
vector<int> aq[100009];

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
  if(r[idx1] > r[idx2])
  {
    p[idx2] = p[idx1];
  }
  else
  {
    p[idx1] = p[idx2];
  }
  if(r[idx1] == r[idx2])
  {
    r[idx2]++;
  }
}

void unionSet(int idx1, int idx2)
{
  int pidx1 = findSet(idx1);
  int pidx2 = findSet(idx2);
  if(pidx1 != pidx2)
  {
    link(pidx1, pidx2);
  }
}

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 100009; i++)
  {
    edges[i].clear();
    aq[i].clear();
  }
  #endif
  q.clear();
  memset(solo, 1, sizeof(solo));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    p[i] = i;
    r[i] = 0;
  }
  packCnt = 0;
  askCnt = 0;
  for(int i = 0; i < m; i++)
  {
    int t;
    scanf("%d", &t);
    if(t == 1)
    {
      int f, s;
      scanf("%d %d", &f, &s);
      f--;
      s--;
      q.push_back(make_pair(f, s));
      solo[f] = false;
      edges[s].push_back(f);
    }
    else if(t == 2)
    {
      scanf("%d", &packs[packCnt]);
      packs[packCnt]--;
      q.push_back(make_pair(-2, packCnt));
      packCnt++;
    }
    else if(t == 3)
    {
      scanf("%d %d", &ask[askCnt].first, &ask[askCnt].second);
      ask[askCnt].first--;
      ask[askCnt].second--;
      aq[ask[askCnt].second].push_back(askCnt);
      q.push_back(make_pair(-3, askCnt));
      askCnt++;
    }
  }
}

bool visited[100009];
int timeIn[100009], timeOut[100009];
int dfsTime;

void dfs(int vertex)
{
  visited[vertex] = true;
  timeIn[vertex] = ++dfsTime;
  for(vector<int>::iterator it = edges[vertex].begin(); it != edges[vertex].end(); ++it)
  {
    if(!visited[*it])
    {
      dfs(*it);
    }
  }
  timeOut[vertex] = ++dfsTime;
}

bool answer[100009];

void Solve()
{
  memset(visited, 0, sizeof(visited));
  memset(timeOut, 0, sizeof(timeOut));
  memset(timeIn, 0, sizeof(timeIn));
  dfsTime = 0;
  for(int i = 0; i < n; i++)
  {
    if(solo[i])
    {
      dfs(i);
    }
  }
  //printf("stage 1 completed\n");
  for(vector<pair<int, int>>::iterator it = q.begin(); it != q.end(); ++it)
  {
    if(it->first >= 0)
    {
      unionSet(it->first, it->second);
    }
    if(it->first == -2)
    {
      for(vector<int>::iterator it2 = aq[it->second].begin(); it2 != aq[it->second].end(); ++it2)
      {
        if((packs[ask[*it2].second] == ask[*it2].first)
        || (findSet(packs[ask[*it2].second]) == findSet(ask[*it2].first)
              && timeIn[ask[*it2].first] < timeIn[packs[ask[*it2].second]]
              && timeOut[ask[*it2].first] > timeOut[packs[ask[*it2].second]]))
        {
          answer[*it2] = true;
        }
        else
        {
          answer[*it2] = false;
        }
      }
    }
  }
}

void WriteData()
{
  for(int i = 0; i < askCnt; i++)
  {
    if(answer[i])
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  printf("\n");
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
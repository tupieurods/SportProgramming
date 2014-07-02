#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
bool used[10009];
int parent[10009], parentCheck[10009];
vector<int> g[10009];

void ReadData()
{
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 10009; i++)
  {
    g[i].clear();
  }
  #endif
  scanf("%d", &n);
  memset(used, 0, sizeof(used));
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &parent[i]);
    if(i != parent[i])
    {
      g[parent[i]].push_back(i);
    }
  }
}

vector<pair<int, int>> answer;
bool showA;
int roundNum;
int dfsu[10009];
int ranks[10009];

void dfs(int v)
{
  if(dfsu[v] == roundNum)//cycle
  {
    showA = false;
    return;
  }
  dfsu[v] = roundNum;
  vector<pair<int, int>> checker;
  for(vector<int>::iterator it = g[v].begin(); it != g[v].end(); it++)
  {
    if(dfsu[*it] == 0)
    {
      dfs(*it);
      if(!showA)
      {
        return;
      }
    }
    checker.push_back(make_pair(ranks[*it], *it));
  }
  sort(checker.begin(), checker.end());
  set<int> s;
  int current = 0, prev = 0;
  for(vector<pair<int, int>>::iterator it = checker.begin(); it != checker.end(); it++)
  {
    /*if(it->first != current && it->first != current - 1)
    {
      showA = false;
      return;
    }*/
/*    if(it == checker.begin() || (prev == it->first && current == prev))
    {
      current++;
    }*/
    //prev = it->first;
    s.insert(it->first);
    answer.push_back(make_pair(v, it->second));
  }
  for(set<int>::iterator it = s.begin(); it != s.end(); it++)
  {
    if(*it != current)
    {
      showA = false;
      return;
    }
    current++;
  }
  ranks[v] = current;
}

void unionCHM(int v1, int v2)
{
  if(ranks[v1] == ranks[v2])
  {
    ranks[v1]++;
  }
  if(ranks[v1] > ranks[v2])
  {
    parentCheck[v2] = v1;
  }
  else
  {
    parentCheck[v1] = v2;
  }
}

void Solve()
{
  showA = true;
  answer.clear();
  roundNum = 0;
  memset(dfsu, 0, sizeof(dfsu));
  memset(ranks, 0, sizeof(ranks));
  for(int i = 1; i <= n; i++)
  {
    if(dfsu[i] == 0)
    {
      roundNum++;
      dfs(i);
      if(!showA)
      {
        return;
      }
    }
  }
  memset(ranks, 0, sizeof(ranks));
  for(int i = 1; i <= n; i++)
  {
    parentCheck[i] = i;
  }
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    unionCHM(it->first, it->second);
  }
  for(int i = 1; i <= n; i++)
  {
    if(parent[i] != parentCheck[i])
    {
      showA = false;
      return;
    }
  }
}

void WriteData()
{
  if(showA)
  {
    printf("%d\n", answer.size());
    for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
    {
      printf("%d %d\n", it->first, it->second);
    }
  }
  else
  {
    printf("-1\n");
  }
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
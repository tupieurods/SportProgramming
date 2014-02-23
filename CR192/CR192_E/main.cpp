#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

using namespace std;

int n, m;
int v[100009][2];

bool comparer(vector<int> &v1, vector<int> &v2)
{
  return v1.size() > v2.size();
}

void ReadData()
{
  memset(v, 0xFF, sizeof(v));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d %d", &from, &to);
    if(v[from][0] != -1)
    {
      v[from][1] = to;
    }
    else
    {
      v[from][0] = to;
    }
    if(v[to][0] != -1)
    {
      v[to][1] = from;
    }
    else
    {
      v[to][0] = from;
    }
  }
}

vector<pair<int, int>> answer;
int checker[8];

int cntBitsOn(int value)
{
  int result = 0;
  while(value != 0)
  {
    result += value & 1 != 0 ? 1 : 0;
    value >>= 1;
  }
  return result;
}

void SolveBrute()
{
  vector<pair<int, int>> edges;
  for(int i = 1; i < n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      if(v[i][0] == j || v[i][1] == j)
      {
        continue;
      }
      edges.push_back(make_pair(i, j));
    }
  }
  //printf("%d\n", edges.size());
  int cnt = 1 << edges.size();
  for(int mask = 1; mask < cnt; mask++)
  {
    if(m != cntBitsOn(mask))
    {
      continue;
    }
    memset(checker, 0, sizeof(checker));
    int index = 0;
    int copy = mask;
    while(copy != 0)
    {
      if(copy & 1 != 0)
      {
        checker[edges[index].first]++;
        checker[edges[index].second]++;
      }
      index++;
      copy >>= 1;
    }
    bool flag = true;
    for(int T = 1; T <= n; T++)
    {
      if(checker[T] > 2)
      {
        flag = false;
        break;
      }
    }
    if(flag)
    {
      index = 0;
      copy = mask;
      while(copy != 0)
      {
        if(copy & 1 != 0)
        {
          answer.push_back(edges[index]);
        }
        index++;
        copy >>= 1;
      }
      break;
    }
  }
}

int colors[100009];
vector<vector<int>> components;

void dfsVisit(int);

void dfs()
{
  components.clear();
  memset(colors, 0, sizeof(colors));
  for(int i = 1; i <= n; i++)
  {
    if(colors[i] == 0)
    {
      components.push_back(vector<int>());
      dfsVisit(i);
    }
  }
}

void dfsVisit(int vertex)
{
  colors[vertex] = 1;
  components[components.size() - 1].push_back(vertex);
  for(int i = 0; i < 2; i++)
  {
    if(v[vertex][i] != -1 && colors[v[vertex][i]] == 0)
    {
      dfsVisit(v[vertex][i]);
    }
  }
  //components[components.size() - 1].push_back(vertex);
  colors[vertex] = 2;
}

void Solve()
{
  answer.clear();
  if(n <= 7)
  {
    SolveBrute();
    return;
  }
  for(int i = 1; i <= n; i++)
  {
    if(v[i][1] != -1 && v[v[i][1]][1] != -1)//Больше связей, больше приоритет
    {
      swap(v[i][1], v[i][0]);
    }
  }
  dfs();
  sort(components.begin(), components.end(), comparer);
  //printf("phase 1 done\n");
  list<int> ansSeq;
  bool first = true;
  for(vector<vector<int>>::iterator it = components.begin(); it != components.end(); it++)
  {
    if((it->size() > 2) && (it->size() % 2 == 0))
    {
      swap((*it)[0], (*it)[2]);
    }
    int cnt = it->size() / 2 + it->size() % 2;
    list<int>::iterator listIter = ansSeq.begin();
    int index = 0;
    for(int T = 0; T < 2; T++)
    {
      index = T;
      cnt = T == 0 ? it->size() / 2 + it->size() % 2 : it->size() / 2;
      for(int i = 0; i < cnt; i++)
      {
        if(!first)
        {
          listIter++;
          listIter = ansSeq.insert(listIter, (*it)[index]);
          listIter++;
        }
        else
        {
          ansSeq.push_back((*it)[index]);
        }
        index += 2;
      }
    }
    first = false;
  }
  //printf("phase2 completed\n");
  list<int>::iterator it = ansSeq.begin();
  int prev = *it;
  it++;
  for(; it != ansSeq.end(); it++)
  {
    answer.push_back(make_pair(prev, *it));
    prev = *it;
    if(answer.size() == m)
    {
      break;
    }
  }
  if(m == n)
  {
    it = ansSeq.end();
    it--;
    if(*it == *ansSeq.begin())
    {
      throw;
    }
    answer.push_back(make_pair(*it, *ansSeq.begin()));
  }
}

void WriteData()
{
  if(answer.size() != m)
  {
    printf("-1\n");
    return;
  }
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d %d\n", it->first, it->second);
  }
  printf("\n");
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
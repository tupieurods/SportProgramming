#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

int m, n;
vector<string> inputWords;
map<string, int> mapping;
int wCnt;
vector<int> edges[600009], edges2[600009];
pair<pair<int, int>, int> v[600009];

pair<int, int> getPair(const string &str)
{
  pair<int, int> result = make_pair(0, str.length());
  for(int i = 0; i < result.second; i++)
  {
    if(str[i] == 'r')
    {
      result.first++;
    }
  }
  return result;
}

void ReadData()
{
  cin >> m;
  inputWords.clear();
  mapping.clear();
  wCnt = 0;
  string str1, str2;
  for(int i = 0; i < m; i++)
  {
    cin >> str1;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    if(mapping.find(str1) == mapping.end())
    {
      mapping.insert(make_pair(str1, wCnt));
      v[wCnt] = make_pair(getPair(str1), wCnt);
      wCnt++;
    }
    inputWords.push_back(str1);
  }
  cin >> n;
  #ifndef ONLINE_JUDGE
  for(int i = 0; i < 600009; i++)
  {
    edges[i].clear();
    edges2[i].clear();
  }
  #endif
  for(int i = 0; i < n; i++)
  {
    cin >> str1 >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    if(mapping.find(str1) == mapping.end())
    {
      mapping.insert(make_pair(str1, wCnt));
      v[wCnt] = make_pair(getPair(str1), wCnt);
      wCnt++;
    }
    if(mapping.find(str2) == mapping.end())
    {
      mapping.insert(make_pair(str2, wCnt));
      v[wCnt] = make_pair(getPair(str2), wCnt);
      wCnt++;
    }
    edges[mapping[str1]].push_back(mapping[str2]);
    edges2[mapping[str2]].push_back(mapping[str1]);
  }
}

pair<__int64, __int64> answer;
int dfsTime;
int dfsEnd[600009];
bool used[600009];
set<pair<int, int>> s;

void dfs1(int idx)
{
  used[idx] = true;
  dfsTime++;
  for(vector<int>::iterator it = edges[idx].begin(); it != edges[idx].end(); ++it)
  {
    if(!used[*it])
    {
      dfs1(*it);
    }
  }
  dfsEnd[idx] = ++dfsTime;
}

vector<vector<int>> components;
int compId[600009];
vector<pair<int, int>> compV;

void dfs2(int idx)
{
  used[idx] = false;
  for(vector<int>::iterator it = edges2[idx].begin(); it != edges2[idx].end(); ++it)
  {
    if(used[*it])
    {
      dfs2(*it);
    }
  }
  //actually we should add to the begin of vector, but it doesn't matter in this task
  components[components.size() - 1].push_back(idx);
  compId[idx] = components.size() - 1;
}

void dfs3(int idx)
{
  used[idx] = true;
  for(vector<int>::iterator it = edges2[idx].begin(); it != edges2[idx].end(); ++it)
  {
    if(!used[*it])
    {
      dfs3(*it);
    }
    compV[idx] = min(compV[idx], compV[*it]);
  }
}

void Solve()
{
  answer = make_pair(0, 0);
  //sort(v, v + wCnt);
  memset(used, 0, sizeof(used));
  dfsTime = 0;
  for(int i = 0; i < wCnt; i++)
  {
    if(!used[i])
    {
      dfs1(i);
    }
  }
  s.clear();
  for(int i = 0; i < wCnt; i++)
  {
    s.insert(make_pair(-dfsEnd[i], i));
  }
  //printf("Part1 finished\n");
  components.clear();
  set<pair<int, int>>::iterator itS;
  //memset(used, 0, sizeof(used));
  for(int i = 0; i < wCnt; i++)
  {
    itS = s.begin();
    if(used[itS->second])
    {
      components.push_back(vector<int>());
      dfs2(itS->second);
    }
    s.erase(itS);
  }
  for(int i = 0; i < wCnt; i++)
  {
    edges2[i].clear();
  }
  compV.clear();
  memset(used, 0, sizeof(used));
  for(vector<vector<int>>::iterator itO = components.begin(); itO != components.end(); ++itO)
  {
    pair<int, int> res = make_pair(INT_MAX, INT_MAX);
    for(vector<int>::iterator it = itO->begin(); it != itO->end(); ++it)
    {
      res = min(res, v[*it].first);
    }
    compV.push_back(res);
  }
  for(int i = 0; i < wCnt; i++)
  {
    for(vector<int>::iterator it = edges[i].begin(); it != edges[i].end(); ++it)
    {
      if(compId[*it] != compId[i])
      {
        edges2[compId[i]].push_back(compId[*it]);
      }
    }
  }
  int compCnt = components.size();
  for(int i = 0; i < compCnt; i++)
  {
    if(!used[i])
    {
      dfs3(i);
    }
  }
  for(vector<string>::iterator it = inputWords.begin(); it != inputWords.end(); ++it)
  {
    int idx = compId[mapping[*it]];
    answer.first += compV[idx].first;
    answer.second += compV[idx].second;
  }
}

void WriteData()
{
  cout << answer.first << " " << answer.second << endl;
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //scanf("%d", &QWE);
  cin >> QWE;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
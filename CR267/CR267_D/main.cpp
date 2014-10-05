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
vector<int> edges[600009];
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
    edges[mapping[str2]].push_back(mapping[str1]);
  }
}

pair<__int64, __int64> answer;
bool used[600009];
pair<int, int> res[600009];
int remapping2[600009];

void dfs(int idx, pair<int, int> &toSet)
{
  int realIdx = v[idx].second;
  res[realIdx] = toSet;
  used[realIdx] = true;
  for(vector<int>::iterator it = edges[realIdx].begin(); it != edges[realIdx].end(); ++it)
  {
    if(!used[*it])
    {
      dfs(remapping2[*it], toSet);
    }
  }
}

void Solve()
{
  answer = make_pair(0, 0);
  sort(v, v + wCnt);
  for(int i = 0; i < wCnt; i++)
  {
    remapping2[v[i].second] = i;
  }
  memset(used, 0, sizeof(used));
  for(int i = 0; i < wCnt; i++)
  {
    if(!used[v[i].second])
    {
      dfs(i, v[i].first);
    }
  }
  for(vector<string>::iterator it = inputWords.begin(); it != inputWords.end(); ++it)
  {
    int idx = mapping[*it];
    answer.first += res[idx].first;
    answer.second += res[idx].second;
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
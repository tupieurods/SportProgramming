#include <string>
#include <iostream>
#include <deque>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#pragma comment(linker, "/STACK:5000000000")

using namespace std;

struct newPair
{
  int first;
  string second;
  int len;
};

__int64 answer;
int n, dfsStrLen, patternLen;
deque<newPair> *edges;
string pattern;
string tmpDfsStr;
int z[300009];
bool first;

void ReadData()
{
  cin >> n;
  edges = new deque<newPair>[n];
  for(int i = 1; i < n; i++)
  {
    newPair ppp;
    ppp.first = i;
    int parent;
    cin >> parent >> ppp.second;
    ppp.len = ppp.second.length();
    edges[parent - 1].push_back(ppp);
  }
  cin >> pattern;
  patternLen = pattern.length();
  pattern += "$";
}

void dfsVisit(int, int);
void dfs()
{
  int len = edges[0].size();
  for(int i = 0; i < len; i++)
  {
    dfsStrLen = 0;
    tmpDfsStr.insert(dfsStrLen, edges[0][i].second);
    dfsStrLen = edges[0][i].len;
    dfsVisit(edges[0][i].first, edges[0][i].len);
  }
}

char getCharFromCheckStr(int pos, int from)
{
  if(pos < pattern.length())
    return pattern.at(pos);
  return tmpDfsStr.at(pos - (patternLen + 1) + from);
}

void calcZ(int from, int prev)
{
  int len = patternLen + 1 + (dfsStrLen - from);
  int l = 0, r = 0;
  int startF = first ? patternLen + 1 : 1;
  first = true;
  for(int i = startF; i < len; i++)
  {
    z[i] = 0;
    if(i <= r)
    {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < len && 
      getCharFromCheckStr(i + z[i], from) == getCharFromCheckStr(z[i], from))
      z[i]++;
    if(i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
    if(z[i] == patternLen)
      answer++;
  }
}

void dfsVisit(int to, int prev)
{
  int len = dfsStrLen;
  if(len >= patternLen)
  {
    int from = 0;
    if(len - prev - (patternLen - 1) > 0)
      from = len - prev - (patternLen - 1);
    calcZ(from, prev);
  }
  int sz = edges[to].size();
  
  for(int i = 0; i < sz; i++)
  {
    //tmpDfsStr.insert(dfsStrLen, edges[to][i].second);
    for(int j = 0; j < edges[to][i].len; j++)
    {
      tmpDfsStr[dfsStrLen + j] = edges[to][i].second[j];
    }
    dfsStrLen += edges[to][i].len;
    dfsVisit(edges[to][i].first, edges[to][i].len);
    dfsStrLen -= edges[to][i].len;
  }
}

void Solve()
{
  answer = 0LL;
  //tmpDfsStr.reserve(300009);
  tmpDfsStr.resize(300009);
  dfs();
}

void WriteData()
{
  cout << answer << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    cout << 1 << endl;
    cout << 100000 << endl;
    for(int i = 0; i < 100000 - 1; i++)
    {
      cout << i + 1 << " aa\n";
    }
    for(int i = 0; i < 100000; i++)
      cout << "a";
    cout << endl;
    return 0;
  }

  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T <QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}


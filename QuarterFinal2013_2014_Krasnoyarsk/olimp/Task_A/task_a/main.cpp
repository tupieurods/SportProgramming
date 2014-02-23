#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

map<__int64, vector< pair<int,int> > > m;
string s;
int k, len;
__int64 mod = 1000000009;

void ReadData()
{
  cin >> k;
  cin >> s;
  len = s.length();
}

int answer;

int getCode(const char &c)
{
  if(c == 'A')
  {
    return 1;
  }
  else if(c == 'C')
  {
    return 2;
  }
  else if(c == 'G')
  {
    return 3;
  }
  else if(c == 'T')
  {
    return 4;
  }
}

void Solve()
{
  answer = 0;
  m.clear();
  __int64 hash = 0;
  __int64 st = 1LL;
  for(int i = 0; i < k; i++)
  {
    hash = getCode(s[i]) + 5 * hash;
    st *= 5;
  }
  st /= 5;
  __int64 prev = hash;
  m.insert(make_pair(hash, vector<pair<int, int>>()));
  m[hash].push_back(make_pair(0, 0));
  map<__int64, vector<pair<int,int>>>::iterator it;
  int idxPrev = 0;
  for(int i = 1; i + k <= len; i++)
  {
    hash = (hash - getCode(s[i - 1]) * st) * 5 + getCode(s[i - 1 + k]);
    it = m.find(hash);
    if(it == m.end())
    {
      m.insert(make_pair(hash, vector<pair<int, int>>()));
      m[hash].push_back(make_pair(i, 0));
      it = m.find(prev);
      it->second[idxPrev].second++;
    }
    else
    {
      idxPrev = -1;
      for(vector<pair<int, int>>::iterator shit = it->second.begin(); shit != it->second.end(); shit++)
      {
        bool flag = true;
        for(int j = 0; j < k; j++)
        {
          if()
        }
        if(flag)
        {
        }
      }
      if(idxPrev == -1)
      {
        it->second.push_back(make_pair(i, 0));
        idxPrev = it->second.size();
      }
    }
    prev = hash;
  }
  for(it = m.begin(); it != m.end(); it++)
  {
    for(vector<pair<int, int>>::iterator shit = it->second.begin(); shit != it->second.end(); shit++)
    {
      if(shit->second > 1)
      {
        answer++;
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE = 1;
  freopen("DEBRUIJN.IN", "r", stdin);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
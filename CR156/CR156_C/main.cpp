#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int b[4000];
map<int, vector<int>> bPos;
map<int, vector<int>>::iterator it;
set<int> used;

void ReadData()
{
  #ifndef ONLINE_JUDGE
  used.clear();
  bPos.clear();
  #endif
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
    it = bPos.find(b[i]);
    if(it != bPos.end())
    {
      it->second.push_back(i);
    }
    else
    {
      bPos.insert(make_pair(b[i], vector<int>()));
      bPos[b[i]].push_back(i);
    }
  }
}

int answer;

void Solve()
{
  answer = 1;
  map<int, vector<int>>::iterator it2;
  vector<int>::iterator vIt;
  for(int i = 0; i < n; i++)
  {
    if(used.find(b[i]) != used.end())
      continue;
    used.insert(b[i]);
    it = bPos.find(b[i]);
    for(int j = i + 1; j < n; j++)
    {
      int current = 2;
      it2 = bPos.find(b[j]);
      int prev = j;
      bool flag = true;
      while(true)
      {
        if(flag)
        {
          vIt = upper_bound(it->second.begin(), it->second.end(), prev);
          if(vIt == it->second.end())
            break;
        }
        else
        {
          vIt = upper_bound(it2->second.begin(), it2->second.end(), prev);
          if(vIt == it2->second.end())
            break;
        }
        prev = *vIt;
        current++;
        flag = !flag;
      }
      answer = max(answer, current);
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
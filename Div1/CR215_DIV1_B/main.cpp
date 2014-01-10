#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, p;
int a[200009], b[200009];
map<int, int> map_b;
map<int, int>::iterator mIt, mIt1;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &p);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
  map_b.clear();
  for(int i = 1; i <= m; i++)
  {
    scanf("%d", &b[i]);
    mIt = map_b.find(b[i]);
    if(mIt == map_b.end())
    {
      map_b.insert(make_pair(b[i], 1));
    }
    else
    {
      mIt->second++;
    }
  } 
}

vector<int> answer;

void Solve()
{
  answer.clear();
  set<int> notVisited;
  for(int i = 1; i <= n; i++)
  {
    notVisited.insert(i);
  }
  map<int, int> good, bad;
  while(true)
  {
    if(notVisited.size() == 0 || *notVisited.begin() + (m - 1) * 1LL * p > n)
    {
      break;
    }
    int startFrom = *notVisited.begin();
    notVisited.erase(notVisited.begin());
    good.clear();
    bad.clear();
    for(int i = 0; i < m; i++)
    {
      int current = a[startFrom + i * p];
      mIt = map_b.find(current);
      if(mIt == map_b.end())
      {
        mIt = bad.find(current);
        if(mIt == bad.end())
        {
          bad.insert(make_pair(current, 1));
        }
        else
        {
          mIt->second++;
        }
      }
      else
      {
        mIt1 = good.find(current);
        if(mIt1 == good.end())
        {
          good.insert(make_pair(current, 1));
        }
        else
        {
          if(mIt1->second < mIt->second)
          {
            mIt1->second++;
          }
          else
          {
            mIt = bad.find(current);
            if(mIt == bad.end())
            {
              bad.insert(make_pair(current, 1));
            }
            else
            {
              mIt->second++;
            }
          }
        }
      }
    }
    while(startFrom + (m - 1) * 1LL * p <= n)
    {
      if(bad.size() == 0)
      {
        answer.push_back(startFrom);
      }
      mIt = bad.find(a[startFrom]);
      if(mIt != bad.end())
      {
        if(mIt->second == 1)
        {
          bad.erase(mIt);
        }
        else
        {
          mIt->second--;
        }
      }
      else
      {
        mIt = good.find(a[startFrom]);
        if(mIt->second == 1)
        {
          good.erase(mIt);
        }
        else
        {
          mIt->second--;
        }
      }
      startFrom += p;
      if(startFrom + (m - 1) * 1LL * p > n)
      {
        break;
      }
      notVisited.erase(startFrom);
      int current = a[startFrom + (m - 1) * p];
      mIt = map_b.find(current);
      if(mIt == map_b.end())
      {
        mIt = bad.find(current);
        if(mIt == bad.end())
        {
          bad.insert(make_pair(current, 1));
        }
        else
        {
          mIt->second++;
        }
      }
      else
      {
        mIt1 = good.find(current);
        if(mIt1 == good.end())
        {
          good.insert(make_pair(current, 1));
        }
        else
        {
          if(mIt1->second < mIt->second)
          {
            mIt1->second++;
          }
          else
          {
            mIt = bad.find(current);
            if(mIt == bad.end())
            {
              bad.insert(make_pair(current, 1));
            }
            else
            {
              mIt->second++;
            }
          }
        }
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  if(answer.size() > 0)
  {
    sort(answer.begin(), answer.end());
    for(vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
    {
      printf("%d ", *it);
    }
    printf("\n");
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
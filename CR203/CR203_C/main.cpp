#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v[4];

bool comparer0(pair<int, int> v1, pair<int, int> v2)
{
  if(v1.first == v2.first)
  {
    return v1.second < v2.second;
  }
  return v1.first < v2.first;
}

bool comparer1(pair<int, int> v1, pair<int, int> v2)
{
  if(v1.first == v2.first)
  {
    return v1.second < v2.second;
  }
  return v1.first > v2.first;
}

bool comparer2(pair<int, int> v1, pair<int, int> v2)
{
  if(v1.first == v2.first)
  {
    return v1.second > v2.second;
  }
  return v1.first > v2.first;
}

bool comparer3(pair<int, int> v1, pair<int, int> v2)
{
  if(v1.first == v2.first)
  {
    return v1.second > v2.second;
  }
  return v1.first < v2.first;
}

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < 4; i++)
  {
    v[i].clear();
  }
  for(int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    if(x >= 0 && y >= 0)
    {
      v[0].push_back(make_pair(x, y));
    }
    else if(x <= 0 && y >= 0)
    {
      v[1].push_back(make_pair(x, y));
    }
    else if(x <= 0 && y <= 0)
    {
      v[2].push_back(make_pair(x, y));
    }
    else if(x >= 0 && y <= 0)
    {
     v[3].push_back(make_pair(x, y));
    }
  }
  sort(v[0].begin(), v[0].end(), comparer0);
  sort(v[1].begin(), v[1].end(), comparer1);
  sort(v[2].begin(), v[2].end(), comparer2);
  sort(v[3].begin(), v[3].end(), comparer3);
}

vector<int> steps;
vector<pair<int, char>> dirSteps;
char moves[4][4] = 
{
  {'R', 'U', 'D', 'L'},
  {'L', 'U', 'D', 'R'},
  {'L', 'D', 'U', 'R'},
  {'R', 'D', 'U', 'L'},
};

void Solve()
{
  steps.clear();
  dirSteps.clear();
  for(int i = 0; i < 4; i++)
  {
    for(vector<pair<int, int>>::iterator it = v[i].begin(); it != v[i].end(); it++)
    {
      if(it->first != 0)
      {
        steps.push_back(1);
        dirSteps.push_back(make_pair(std::abs(it->first), moves[i][0]));
      }
      if(it->second != 0)
      {
        steps.push_back(1);
        dirSteps.push_back(make_pair(std::abs(it->second), moves[i][1]));
      }
      steps.push_back(2);
      if(it->second != 0)
      {
        steps.push_back(1);
        dirSteps.push_back(make_pair(std::abs(it->second), moves[i][2]));
      }
      if(it->first != 0)
      {
        steps.push_back(1);
        dirSteps.push_back(make_pair(std::abs(it->first), moves[i][3]));
      }
      steps.push_back(3);
    }
  }
}

void WriteData()
{
  printf("%d\n", steps.size());
  vector<pair<int, char>>::iterator it2 = dirSteps.begin();
  for(vector<int>::iterator it = steps.begin(); it != steps.end(); it++)
  {
    printf("%d ", *it);
    if(*it == 1)
    {
      printf("%d %c\n", it2->first, it2->second);
      it2++;
    }
    else
    {
      printf("\n");
    }
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>

using namespace std;

struct vertex
{
  string name;
  int rowspan, level;
  deque<int> childIds;
};

int n;
deque<vertex> verticies;
deque<int> levelVerticiesIds[10];
int maxLevel;

void ReadData()
{
  for(int i = 0; i < 10; i++)
    levelVerticiesIds[i].clear();
  verticies.clear();
  scanf("%d\n", &n);
  maxLevel = 0;
  for(int i = 0; i < n; i++)
  {
    vertex tmp;
    getline(cin, tmp.name);
    tmp.level = 0;
    while(tmp.name[tmp.level] == ' ')
      tmp.level++;
    tmp.rowspan = 0;
    maxLevel = max(maxLevel, tmp.level);
    tmp.name = tmp.name.substr(tmp.level);
    verticies.push_back(tmp);
    levelVerticiesIds[tmp.level].push_back(i);
  }
}

void Solve()
{
  for(int i = 0; i < 10; i++)
  {
    if(levelVerticiesIds[i].size() == 0)
      break;
    int ind = 0;
    int first = true;
    int cnt = 0;
    for(int j = 0; j < n; j++)
    {
      if(verticies[j].level == i)
      {
        if(first)
        {
          first = false;
          continue;
        }
        verticies[levelVerticiesIds[i][ind]].rowspan += cnt;
        ind++;
        cnt = 0;
      }
      else if(verticies[j].level == maxLevel)
      {
        cnt++;
      }
    }
    if(cnt != 0)
    {
      verticies[levelVerticiesIds[i][ind]].rowspan += cnt;
    }
  }
}

void WriteData()
{
  cout << "<table>\n";
  deque<int> answerIds;
  int prev = -1;
  for(int i = 0; i < n; i++)
  {
    answerIds.push_back(i);
    if(verticies[i].level == maxLevel)
    {
      cout << "<tr>\n";
      for(int j = 0; j < answerIds.size(); j++)
      {
        if(verticies[answerIds[j]].rowspan == 0)
          verticies[answerIds[j]].rowspan = 1;
        cout << "  <td rowspan=" << verticies[answerIds[j]].rowspan
          << ">" << verticies[answerIds[j]].name << "</td>\n";
      }
      cout << "</tr>\n";
      answerIds.clear();
    }
  }
  cout << "</table>" << endl;
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m;
//map<int, vector<pair<int, int>>> edges;
vector<pair<int, int>> edges[100009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int from, to, w;
    scanf("%d %d %d", &from, &to, &w);
    edges[w].push_back(make_pair(from, to));
  }
}

int answer;
vector<pair<int, int>> updates;
int dp[300009];

/*void Solve()
{
  answer = 0;
  memset(dp, 0, sizeof(dp));
  for(map<int, vector<pair<int, int>>>::iterator it = edges.begin();
    it != edges.end(); ++it)
  {
    updates.clear();
    for(vector<pair<int, int>>::iterator itV = it->second.begin(); itV != it->second.end(); ++itV)
    {
      if(dp[itV->first] + 1 > dp[itV->second])
      {
        answer = max(answer, dp[itV->first] + 1);
        updates.push_back(make_pair(itV->second, dp[itV->first] + 1));
      }
    }
    for(vector<pair<int, int>>::iterator itV = updates.begin(); itV != updates.end(); ++itV)
    {
      dp[itV->first] = max(itV->second, dp[itV->first]);
    }
  }
}*/

void Solve2()
{
  answer = 0;
  memset(dp, 0, sizeof(dp));
  for(int i = 0; i < 100009; i++)
  {
    updates.clear();
    for(vector<pair<int, int>>::iterator itV = edges[i].begin(); itV != edges[i].end(); ++itV)
    {
      if(dp[itV->first] + 1 > dp[itV->second])
      {
        answer = max(answer, dp[itV->first] + 1);
        updates.push_back(make_pair(itV->second, dp[itV->first] + 1));
      }
    }
    for(vector<pair<int, int>>::iterator itV = updates.begin(); itV != updates.end(); ++itV)
    {
      dp[itV->first] = max(itV->second, dp[itV->first]);
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
    //Solve();
    Solve2();
    WriteData();
  }
  return 0;
}
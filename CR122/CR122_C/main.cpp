#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, m, s;
int matrix[59][59];
vector<pair<int, int>> v;

void ReadData()
{
  memset(matrix, 0xFF, sizeof(matrix));
  v.clear();
  s = 0;
  scanf("%d %d%*c", &n, &m);
  char str[59];
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < m; j++)
    {
      if(str[j] == '#')
      {
        matrix[i][j] = s;
        s++;
        v.push_back(make_pair(i, j));
      }
    }
  }
}

int bfsMatrix[59][59];
int current;
int directions[4][2] = 
{
  {1, 0},
  {-1, 0},
  {0, -1},
  {0, 1}
};

int bfs(int start, int excluded)
{
  queue<int> q;
  q.push(start);
  bfsMatrix[v[start].first][v[start].second] = current;
  int result = 1;

  while(!q.empty())
  {
    int currentVertex = q.front();
    q.pop();
    for(int i = 0; i < 4; i++)
    {
      if(v[currentVertex].first + directions[i][0] >= 0 && v[currentVertex].first + directions[i][0] < n
        && v[currentVertex].second + directions[i][1] >= 0 && v[currentVertex].second + directions[i][1] < m
        && matrix[v[currentVertex].first + directions[i][0]][v[currentVertex].second + directions[i][1]] != -1
        && matrix[v[currentVertex].first + directions[i][0]][v[currentVertex].second + directions[i][1]] != excluded
        && bfsMatrix[v[currentVertex].first + directions[i][0]][v[currentVertex].second + directions[i][1]] != current)
        {
          result++;
          q.push(matrix[v[currentVertex].first + directions[i][0]][v[currentVertex].second + directions[i][1]]);
          bfsMatrix[v[currentVertex].first + directions[i][0]][v[currentVertex].second + directions[i][1]] = current;
        }
    }
  }

  return result;
}

int answer;

void Solve()
{
  if(s < 3)
  {
    answer = -1;
    return;
  }
  answer = 2;
  memset(bfsMatrix, 0xFF, sizeof(bfsMatrix));
  current = 0;
  if(bfs(1, 0) != s - 1)
  {
    answer = 1;
    return;
  }
  for(int i = 1; i < s; i++)
  {
    current++;
    if(bfs(0, i) != s - 1)
    {
      answer = 1;
      return;
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
  scanf("%d%*c", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
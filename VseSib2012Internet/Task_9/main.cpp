#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int n, m;
char table[109][109];
pair<int, int> firstPoint;

void ReadData()
{
  scanf("%d %d%*c", &n, &m);
  memset(table, 0, sizeof(table));
  firstPoint = make_pair(-1, -1);
  for(int i = 0; i < n; i++)
  {
    scanf("%s%*c", table[i]);
    if(firstPoint.first != -1)
      continue;
    for(int j = 0; j < m; j++)
    {
      if(table[i][j] == '#')
      {
        firstPoint.first = i;
        firstPoint.second = j;
        break;
      }
    }
  }
}

int bfsTable[109][109];
int delta[4][2] = 
{
  {1, 0},
  {-1, 0},
  {0, -1},
  {0, 1}
};

void bfs(pair<int, int> start)
{
  memset(bfsTable, 0xFF, sizeof(bfsTable));
  bfsTable[start.first][start.second] = 0;
  queue<pair<int, int>> q;
  q.push(start);

  while(!q.empty())
  {
    pair<int, int> current = q.front();
    q.pop();

    for(int i = 0; i < 4; i++)
    {
      int newY = current.first + delta[i][0];
      int newX = current.second + delta[i][1];

      if(newY >= 0 && newY < n
        && newX >= 0 && newX < m
        && table[newY][newX] == '#'
        && bfsTable[newY][newX] == -1)
      {
        bfsTable[newY][newX] = bfsTable[current.first][current.second] + 1;
        q.push(make_pair(newY, newX));
      }
    }
  }
}

pair<int, int> points[2];

void afterBfs(int index)
{
  points[index] = make_pair(0, 0);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(bfsTable[i][j] > bfsTable[points[index].first][points[index].second])
      {
        points[index].first = i;
        points[index].second = j;
      }
    }
  }
}

void Solve()
{
  bfs(firstPoint);
  afterBfs(0);
  bfs(points[0]);
  afterBfs(1);
}

void WriteData()
{
  table[points[0].first][points[0].second] = 'X';
  table[points[1].first][points[1].second] = 'X';
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", table[i]);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}
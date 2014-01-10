#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

struct point
{
  int x, y;
};

int r, c;
char matrix[1000][1000];
point door, start;

void ReadData()
{
  scanf("%d %d%*c", &r, &c);
  char str[1009];
  for(int i = 0; i < r; i++)
  {
    scanf("%s%*c", str);
    for(int j = 0; j < c; j++)
    {
      if(str[j] == 'T')
      {
        matrix[i][j] = -1;
        continue;
      }
      if(str[j] == 'E')
      {
        matrix[i][j] = 0;
        door.x = j;
        door.y = i;
        continue;
      }
      if(str[j] == 'S')
      {
        matrix[i][j] = 0;
        start.x = j;
        start.y = i;
        continue;
      }
      matrix[i][j] = (str[j] - '0');
    }
  }
}

int answer;
int dist[1000][1000];
int moves[4][2] = 
{
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
};

void bfs()
{
  memset(dist, 0xFF, sizeof(dist));
  queue<pair<int, int>> Q;
  dist[door.y][door.x] = 0;
  Q.push(make_pair(door.y, door.x));

  while(!Q.empty())
  {
    pair<int, int> current = Q.front();
    Q.pop();

    for(int i = 0; i < 4; i++)
    {
      int nextX = current.second + moves[i][1];
      int nextY = current.first + moves[i][0];
      if(nextX >= 0 && nextY >= 0 && nextY < r && nextX < c
          && dist[nextY][nextX] == -1
          && matrix[nextY][nextX] >= 0)
      {
        dist[nextY][nextX] = dist[current.first][current.second] + 1;
        Q.push(make_pair(nextY, nextX));
      }
    }
  }
}

void Solve()
{
  answer = 0;
  bfs();
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      if(matrix[i][j] > 0)
      {
        if(dist[i][j] != -1 && dist[i][j] <= dist[start.y][start.x])
        {
          answer += matrix[i][j];
        }
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
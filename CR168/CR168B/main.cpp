#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <deque>
#include <queue>
#include <set>

using namespace std;

//#define LOCALTEST

struct point
{
  int x, y;
};

struct vect
{
  point p;
  int dir;
  bool dirChanged;
};

int dirs[4][2] =
{
  {0, -1},
  {1, 0},
  {0, 1},
  { -1, 0},
};

int goLeft(int current)
{
  current--;
  if(current == -1)
    current = 3;
  return current;
}

int goRight(int current)
{
  current++;
  if(current == 4)
    current = 0;
  return current;
}

bool** data;
bool** testMatrix;
deque<point> blackDots;
int n, m;

bool check(int x, int y)
{
  if(y >= 0 && y < n && x >= 0 && x < m && data[y][x])
    return true;
  return false;
}

int getHashCode(int x, int y, int dir, bool changed)
{
  return x * 10000 + y * 100 + dir * 10 + (int)changed;
}

bool bfs(point start)
{
  queue<vect> Q;
  vect toAdd = {start, 0, false};
  Q.push(toAdd);
  toAdd = {start, 1, false};
  Q.push(toAdd);
  toAdd = {start, 2, false};
  Q.push(toAdd);
  toAdd = {start, 3, false};
  Q.push(toAdd);
  set<int> visited;
  for(int i = 0; i < n; i++)
  {
    testMatrix[i] = new bool[m];
    memset(testMatrix[i], 0, sizeof(bool) * m);
  }
  testMatrix[start.y][start.x] = true;

  while(!Q.empty())
  {
    vect current = Q.front();
    Q.pop();
    int currentDirs[3] = {current.dir, goLeft(current.dir), goRight(current.dir)};
    int count = current.dirChanged ? 1 : 3;
    for(int i = 0; i < count; i++)
    {
      vect tmp = {{current.p.x + dirs[currentDirs[i]][0], current.p.y + dirs[currentDirs[i]][1]}, currentDirs[i], i != 0 || current.dirChanged};
      if(check(tmp.p.x, tmp.p.y)
          && visited.find(getHashCode(tmp.p.x, tmp.p.y, tmp.dir, tmp.dirChanged)) == visited.end())
      {
        Q.push(tmp);
        testMatrix[tmp.p.y][tmp.p.x] = true;
      }
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(data[i][j] != testMatrix[i][j])
        return false;
    }
  }
  return true;
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d %d\n", &n, &m);
    data = new bool*[n];
    testMatrix = new bool*[n];
    string str;
    for(int i = 0; i < n; i++)
    {
      getline(std::cin, str);
      data[i] = new bool[m];
      testMatrix[i] = new bool[m];
      for(int j = 0; j < m; j++)
      {
        data[i][j] = str[j] == 'B';
        if(data[i][j])
        {
          point tmp = {j, i};
          blackDots.push_back(tmp);
        }
      }
    }
    bool result = true;
    for(int i = 0; i < (int)blackDots.size(); i++)
    {
      if(!bfs(blackDots[i]))
      {
        result = false;
        break;
      }
    }
    if(result)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

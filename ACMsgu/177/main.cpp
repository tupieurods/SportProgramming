#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
  int x, y;
};

struct query
{
  int lx, ly, rx, ry;
  char c;
};

int n, m;
bool tree[2000000];
int field[1024][1024];
query *q;
point leftTop, rightTop, leftDown, rightDown;
int current;

void ReadData()
{
  scanf("%d %d", &n, &m);
  memset(field, 0xFF, sizeof(field));
  memset(tree, 0, sizeof(tree));
  q = new query[m];
}

bool f(int vertexNum, int x, int y, int size)
{
  if(tree[vertexNum])
    return true;
  if(size == 4)
  {
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        if(field[y + i][x + j] == -1
            && (x + j >= leftTop.x)
            && (x + j <= rightTop.x)
            && (y + i >= leftTop.y)
            && (y + i <= rightDown.y))
          field[y + i][x + j] = current;
        if(field[y + i][x + j] != -1)
          cnt++;
      }
    }
    tree[vertexNum] = cnt == 16;
    return tree[vertexNum];
  }
  bool result = true;
  int centerX = x + size / 2;
  int centerY = y + size / 2;
  if(leftTop.x < centerX && leftTop.y < centerY)
    result = f(vertexNum * 4 + 1,
      x, y, size / 2) && result;
  if(rightTop.x >= centerX && rightTop.y < centerY)
    result = f(vertexNum * 4 + 2,
      x + size / 2, y , size / 2) && result;
  if(leftDown.x < centerX && leftDown.y >= centerY)
    result = f(vertexNum * 4 + 3,
      x, y + size / 2, size / 2) && result;
  if(rightDown.x >= centerX && rightDown.y >= centerY)
    result = f(vertexNum * 4 + 4,
      x + size / 2, y + size / 2, size / 2) && result;
  return result;
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

inline int max(int a, int b)
{
  return a > b ? a : b;
}

void Solve()
{
  for(int i = 0; i < m; i++)
  {
    int lx, ly, rx, ry;
    scanf("%d %d %d %d %c\n", &lx, &ly, &rx, &ry, &q[i].c);
    q[i].lx = min(lx, rx);
    q[i].rx = max(lx, rx);
    q[i].ly = min(ly, ry);
    q[i].ry = max(ly, ry);
  }
  for(int i = m - 1; i >= 0; i--)
  {
    current = q[i].c == 'b' ? 1 : 0;
    leftTop.x = q[i].lx;
    leftTop.y = q[i].ly;
    rightDown.x = q[i].rx;
    rightDown.y = q[i].ry;
    rightTop.x = q[i].rx;
    rightTop.y = q[i].ly;
    leftDown.x = q[i].lx;
    leftDown.y = q[i].ry;
    f(0, 1, 1, 1024);
  }
}

void WriteData()
{
  int answer = 0;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      if(field[i][j] == 0 || field[i][j] == -1)
        answer++;
    }
  }
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
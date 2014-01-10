#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

#define max 1000000000

int x1, y1;
int delta[2][3] = {{ -1, 0, 1}, { -1, 0, 1}};

struct treeVertex
{
  int color, value, x, y;
};

map< __int64, treeVertex > tree;

__int64 calcMapValue(int x, int y)
{
  return (__int64)x * 1000000000 + y;
}

bool canGoTo(int x, int y)
{
  __int64 calcValue = calcMapValue(x, y);
  return ((x >= 1) && (y >= 1) && (x <= max) && (y <= max)
          && (tree.count(calcValue) != 0)
          && (tree[calcValue].color == 0));
}

void bfs(int x, int y)
{
  tree[calcMapValue(x, y)].value = 0;
  queue<__int64> q;
  q.push(calcMapValue(x, y));
  while(!q.empty())
  {
    __int64 current = q.front();
    q.pop();
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if((i == 1) && (j == 1))
          continue;

        if( canGoTo(tree[current].x + delta[0][i], tree[current].y + delta[1][j]))
        {
          __int64 tmp=calcMapValue(tree[current].x + delta[0][i], tree[current].y + delta[1][j]);
          tree[tmp].value = tree[current].value + 1;
          tree[tmp].color = 1;
          q.push(tmp);
        }
      }
    }
    tree[current].color = 2;
  }
}

int main()
{
  int x0, y0;
  scanf("%d %d %d %d", &y0, &x0, &y1, &x1);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int r, a, b;
    scanf("%d %d %d", &r, &a, &b);
    for(int j = a; j <= b; j++)
    {
      if(tree.count(calcMapValue(j, r)) == 0)
      {
        treeVertex addToMap = {0, INT_MAX, j, r};
        tree.insert(make_pair(calcMapValue(j, r), addToMap));
      }
    }
  }
  //Если начальная точка небезопасна
  if(tree.count(calcMapValue(x0, y0)) == 0)
  {
    printf("-1");
    return 0;
  }
  bfs(x0, y0);
  if(tree.count(calcMapValue(x1, y1)) == 0 || tree[calcMapValue(x1, y1)].value == INT_MAX)
    printf("-1");
  else
    printf("%d\n", tree[calcMapValue(x1, y1)].value);
  return 0;
}


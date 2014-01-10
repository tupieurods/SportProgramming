#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

struct edge
{
  int xFrom, yFrom, xTo, yTo;
  int c, f;
  edge *reverse;
};

int n, p;
int matrix[40][40];
vector<edge*> edges;
vector<int> verticies[4142];

inline int residual(edge *current)
{
  return current->c - current->f;
}

void ReadData()
{
  scanf("%d %d", &n, &p);
  memset(matrix, 0, sizeof(matrix));
  #ifndef ONLINE_JUDGE
  edges.clear();
  for(int i = 0; i < 4142; i++)
  {
    verticies[i].clear();
  }
  #endif
  for(int i = 0; i < p; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    matrix[y][x] = 1;
  }
}

void AddEdge(int xFrom, int yFrom, int xTo, int yTo)
{
  edge* current = new edge;
  current->xFrom = xFrom;
  current->yFrom = yFrom;
  current->xTo = xTo;
  current->yTo = yTo;
  current->c = 1;
  current->f = 0;

  edge* reverse = new edge;
  reverse->xFrom = xTo;
  reverse->yFrom = yTo;
  reverse->xTo = xFrom;
  reverse->yTo = yFrom;
  reverse->c = 0;
  reverse->f = 0;

  current->reverse = reverse;
  reverse->reverse = current;

  edges.push_back(current);
  verticies[xFrom * 100 + yFrom].push_back(edges.size() - 1);
  edges.push_back(reverse);
  verticies[xTo * 100 + yTo].push_back(edges.size() - 1);
}

inline bool IsBlack(int x, int y)
{
  if(y % 2 == 1)
  {
    return x % 2 == 0;
  }
  else
  {
    return x % 2 == 1;
  }
}

void BuildGraph()
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(matrix[i][j] == 0)
      {
        int x = j + 1, y = i + 1;
        if(IsBlack(x, y))
        {
          AddEdge(0, 0, x, y);
          if(j + 1 < n && matrix[i][j + 1] == 0)
          {
            AddEdge(x, y, x + 1, y);
          }
          if(i + 1 < n && matrix[i + 1][j] == 0)
          {
            AddEdge(x, y, x, y + 1);
          }
          if(j - 1 >= 0 && matrix[i][j - 1] == 0)
          {
            AddEdge(x, y, x - 1, y);
          }
          if(i - 1 >= 0 && matrix[i - 1][j] == 0)
          {
            AddEdge(x, y, x, y - 1);
          }
        }
        else
        {
          AddEdge(x, y, 41, 41);
        }
      }
    }
  }
}

void dfsVisit(int);
int parents[4142];
void dfs()
{
  memset(parents, 0xFF, sizeof(parents));
  parents[0] = -2;
  for(unsigned int i = 0; i < verticies[0].size(); i++)
  {
    edge *current = edges[verticies[0][i]];
    int code = current->xTo * 100 + current->yTo;
    if(residual(current) > 0 && parents[code] == -1)
    {
      dfsVisit(verticies[0][i]);
      if(parents[4141] != -1)
        break;
    }
  }
}

void dfsVisit(int edgeNumber)
{
  edge *current = edges[edgeNumber];
  int codeTo = current->xTo * 100 + current->yTo;
  parents[current->xTo * 100 + current->yTo] = edgeNumber;
  if(codeTo == 4141)
  {
    return;
  }

  for(unsigned int i = 0; i < verticies[codeTo].size(); i++)
  {
    current = edges[verticies[codeTo][i]];
    int code = current->xTo * 100 + current->yTo;
    if(residual(current) > 0 && parents[code] == -1)
    {
      dfsVisit(verticies[codeTo][i]);
      if(parents[4141] != -1)
        break;
    }
  }
}

int FordFulkerson()
{
  int step = 0;
  while(true)
  {
    dfs();
    if(parents[4141] == -1)
      break;
    int currentCode = 4141;
    int minimal = 0x7F7F7F7F;
    while(parents[currentCode] >= 0)
    {
      minimal = min(residual(edges[parents[currentCode]]), minimal);
      currentCode = edges[parents[currentCode]]->xFrom * 100 + edges[parents[currentCode]]->yFrom;
    }
    currentCode = 4141;
    while(parents[currentCode] >= 0)
    {
      edges[parents[currentCode]]->f += minimal;
      edges[parents[currentCode]]->reverse->f -= minimal;
      currentCode = edges[parents[currentCode]]->xFrom * 100 + edges[parents[currentCode]]->yFrom;
    }
  }
  int result = 0;
  for(unsigned int i = 0; i < verticies[0].size(); i++)
  {
    result += edges[verticies[0][i]]->f;
    /*if(edges[verticies[0][i]]->f < 0)
      throw "Fail";*/
  }
  return result;
}

bool answer;
vector<pair<int, int>> horizontal, vertical;
void Solve()
{
  //edges.clear();
  #ifndef ONLINE_JUDGE
  vertical.clear();
  horizontal.clear();
  #endif
  BuildGraph();
  answer = false;
  if((n * n - p) % 2 == 0)
  {
    int flow = FordFulkerson();
    answer = flow == (n * n - p) / 2;
  }
  if(answer)
  {
    for(unsigned int i = 0; i < verticies[0].size(); i++)
    {
      edge *current = edges[verticies[0][i]];
      if(current->f > 0)
      {
        int code = current->xTo * 100 + current->yTo;
        for(unsigned int j = 0; j < verticies[code].size(); j++)
        {
          current = edges[verticies[code][j]];
          if(current->f > 0)
          {
            if(current->xFrom == current->xTo)//Vertical
            {
              vertical.push_back(make_pair(current->xFrom, min(current->yFrom, current->yTo)));
            }
            else//Horizontal
            {
              horizontal.push_back(make_pair(min(current->xFrom, current->xTo), current->yFrom));
            }
            break;
          }
        }
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("Yes\n");
    vector<pair<int, int>>::iterator it;
    printf("%d\n", horizontal.size());
    for(it = horizontal.begin(); it != horizontal.end(); it++)
    {
      printf("%d %d\n", it->first, it->second);
    }
    printf("%d\n", vertical.size());
    for(it = vertical.begin(); it != vertical.end(); it++)
    {
      printf("%d %d\n", it->first, it->second);
    }
  }
  else
  {
    printf("No\n");
  }
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
#pragma comment(linker, "/stack:20111000")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

using namespace std;

#define Size(v) (v.size())

deque<deque<int>> branches;
deque<int>* verticies;
pair<int, int>* vertexInfo;
int n, q;

struct fenwick
{
  int* arr;
  int count;
};

inline int f(int value)
{
  return value - (value & (value - 1));
}

int max(int a, int b)
{
  return a > b ? a : b;
}

void addValue(fenwick* tree, int pos, int value)
{
  //pos++;
  while(pos <= tree->count)
  {
    tree->arr[pos] += value;
    pos += f(pos);
  }
}

int getSum(fenwick* tree, int pos)
{
  int result = 0;
  //pos++;
  while(pos > 0)
  {
    result += tree->arr[pos];
    pos -= f(pos);
  }
  return result;
}

fenwick* generateTree(int count)
{
  fenwick* result = new fenwick;
  int k = 1;
  while(k < count)
    k <<= 1;
  result->arr = new int[k + 1];
  memset(result->arr, 0 ,sizeof(int) * (k + 1));
  result->count = k;
  return result;
}

bool* visited;
int currentLine;
void dfsVisit(int v);
void dfs()
{
  visited = new bool[n + 1];
  memset(visited, false, sizeof(bool) * (n + 1));
  visited[1] = true;
  currentLine = 0;
  branches.push_back(deque<int>());

  for(int i = 0; i < Size(verticies[1]); i++)
  {
    if(!visited[verticies[1][i]])
    {
      currentLine++;
      branches.push_back(deque<int>());
      dfsVisit(verticies[1][i]);
    }
  }
}

void dfsVisit(int vertex)
{
  visited[vertex] = true;

  for(int i = 0; i < Size(verticies[vertex]); i++)
  {
    if(!visited[verticies[vertex][i]])
    {
      dfsVisit(verticies[vertex][i]);
    }
  }
  branches[currentLine].push_front(vertex);
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
    scanf("%d %d", &n, &q);
    verticies = new deque<int>[n + 1];
    vertexInfo = new pair<int, int>[n + 1];

    for(int i = 1; i < n; i++)
    {
      int from, to;
      scanf("%d %d", &from, &to);
      verticies[from].push_back(to);
      verticies[to].push_back(from);
    }

    dfs();
    deque<fenwick*> trees;
    int maximalDeep = -1;
    for(int i = 1; i <= currentLine; i++)
    {
      maximalDeep = max(maximalDeep, Size(branches[i]));
      trees.push_back(generateTree(Size(branches[i])));
      for(int j = 0; j < Size(branches[i]); j++)
      {
        vertexInfo[branches[i][j]].first = i;//Номер сопли
        vertexInfo[branches[i][j]].second = j + 1;//Позиция в сопле
      }
    }
    fenwick* global = generateTree(maximalDeep + 1);

    for(int i = 0; i < q; i++)
    {
      int action;
      scanf("%d ", &action);
      switch(action)
      {
      case 0:
        {
          int vertex, x, d;
          scanf("%d %d %d\n", &vertex, &x, &d);
          int index = vertexInfo[vertex].second;
          int low = index - d;
          int high = index + d;
          if(vertex == 1)//Если добавляем в корень
          {
            addValue(global, 1, x);
            if(d + 1 < maximalDeep + 1)
              addValue(global, d + 2, -x);
            break;
          }
          if(low > 0)//В пределах сопли
          {
            addValue(trees[vertexInfo[vertex].first - 1], low, x);
            if(high < Size(branches[vertexInfo[vertex].first]))
            {
              addValue(trees[vertexInfo[vertex].first - 1], high + 1, -x);
            }
            break;
          }
          //Задели корень и ещё что-то
          int layer = -low + 1;
          addValue(global, 1, x);
          if(layer < maximalDeep + 1)
            addValue(global, layer + 1, -x);
          if(layer <= high)
          {
            low = layer;
            addValue(trees[vertexInfo[vertex].first - 1], low, x);
            if(high < Size(branches[vertexInfo[vertex].first]))
            {
              addValue(trees[vertexInfo[vertex].first - 1], high + 1, -x);
            }
          }
          break;
        }
      case 1:
        {
          int vertex;
          scanf("%d\n", &vertex);
          if(vertex == 1)
          {
            printf("%d\n", getSum(global, 1));
          }
          else
          {
            printf("%d\n", getSum(global, vertexInfo[vertex].second + 1)
              + getSum(trees[vertexInfo[vertex].first - 1], vertexInfo[vertex].second));
          }
          break;
        }
      }
    }
    branches.clear();
  }
  return 0;
}
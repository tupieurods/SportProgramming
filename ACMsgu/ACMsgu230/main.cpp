#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>* lists;
int* d;//Начальное время обработки
int* f;//Конечное время обработки
int* p;//Массив предков
int* color;//Массив цветов вершин
int currentTime, m, n;
vector<int> topologicSort;
bool haveCycle;

void DFSVisit(int v);

void DFS()
{
  //Обнуление
  haveCycle = false;
  currentTime = 0;
  d = new int[n+1];
  f = new int[n+1];
  p = new int[n+1];
  color = new int[n+1];
  memset(d, 0, sizeof(int)*(n + 1));
  memset(f, 0, sizeof(int)*(n + 1));
  memset(p, 0, sizeof(int)*(n + 1));
  memset(color, 0, sizeof(int)*(n + 1));

  for(int i = 1; i <= n; i++)
  {
    if(color[i] == 0)
    {
      DFSVisit(i);
    }
  }
  reverse(topologicSort.begin(), topologicSort.end());
}

//v-Номер посещаемой вершины
void DFSVisit(int v)
{
  color[v] = 1;
  //d[v] = ++currentTime;
  for(unsigned int i = 0; i < lists[v].size(); i++)
  {
    if(color[lists[v][i]] == 0)
    {
      //p[lists[v][i]] = v;
      DFSVisit(lists[v][i]);
    }
    else if(color[lists[v][i]] == 1)
      haveCycle = true;
  }
  //f[v] = ++currentTime;
  color[v] = 2;
  topologicSort.push_back(v);
}

int main()
{
  scanf("%d %d", &n, &m);
  lists = new vector<int>[n+1];
  //Считывание списков смежности
  for(int i = 0; i < m; i++)
  {
    int p, q;
    scanf("%d %d", &p, &q);
    lists[p].push_back(q);
  }
  DFS();

  if(haveCycle)
  {
    printf("No solution");
    return 0;
  }

  /*for(unsigned int j = 0; j < topologicSort.size(); j++)
  {
    printf("%d ", topologicSort[j]);
  }

  printf("\n");*/

  for(int i = 1; i <= n; i++)
  {
    int tmp;
    for(unsigned int j = 0; j < topologicSort.size(); j++)
    {
      if(topologicSort[j] == i)
      {
        tmp = j;
        break;
      }
    }

    printf("%d ", tmp + 1);
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define LOCALTEST

vector<int>* lists;
vector<int> colors;
deque<int>* anwser;
void dfsVisit(int vertexNum);

struct crater
{
  __int64 x, y, r;
};

void dfs(int vertexCount)
{
  //Время обработки нам не нужно, предки нам тоже без надобности
  //Нужны только цвета
  colors.clear();
  anwser = new deque<int>[vertexCount];
  for(int i = 0; i < vertexCount; i++)
  {
    colors.push_back(0);
    //0 белый
    //1 серый
    //2 чёрный
  }

  for(int i = 0; i < vertexCount; i++)
  {
    if(colors[i] == 0)
      dfsVisit(i);
  }
}

void dfsVisit(int vertexNum)
{
  colors[vertexNum] = 1;
  int maxPos = -1;
  for(unsigned int i = 0; i < lists[vertexNum].size(); i++)
  {
    if(colors[lists[vertexNum][i]] == 0)
    {
      dfsVisit(lists[vertexNum][i]);
    }
    else if(colors[lists[vertexNum][i]] == 2)
    {
      //А ничё не будем делать
    }
    else
    {
      cout << "Someone changed matrix. RUN NEO" << endl;
    }
    if((maxPos == -1) 
      || (anwser[maxPos].size() < anwser[lists[vertexNum][i]].size()))
    {
      maxPos = lists[vertexNum][i];
    }
  }
  if(maxPos != -1)
  {
    anwser[vertexNum].insert(anwser[vertexNum].end(), anwser[maxPos].begin(), anwser[maxPos].end());// += anwser[maxPos];
  }
  anwser[vertexNum].push_front(vertexNum);
  colors[vertexNum] = 2;
}

__int64 pow2(__int64 a)
{
  return a * a;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int QWE;
  #ifdef LOCALTEST
  cin >> QWE;
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    //cout << "Test№" << T + 1 << endl;
    int n;
    cin >> n;
    lists = new vector<int>[n];
    vector<crater> craters;
    for(int i = 0; i < n; i++)
    {
      crater tmp;
      cin >> tmp.x >> tmp.y >> tmp.r;
      craters.push_back(tmp);
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if((i == j) || (craters[i].r < craters[j].r))//Сам в себя кратер не должен вкладываться
          continue;
        __int64 dist = pow2(craters[i].x - craters[j].x) + pow2(craters[i].y - craters[j].y);
        __int64 r2 = pow2(craters[i].r - craters[j].r);
        if(dist <= r2)
        {
          //cout << i + 1 << " " << j + 1 << endl;
          lists[j].push_back(i);
        }
      }
    }
    //Тестирование поиска. Получение готового дерева
    /*int n, e;
    cin >> n >> e;
    lists = new vector<int>[n];
    for(int i = 0; i < e; i++)
    {
      int from, to;
      cin >> from >> to;
      lists[from].push_back(to);
    }*/
    //cout << "dfs" << endl;
    dfs(n);
    int maxPos = 0;
    for(int i = 0; i < n; i++)
    {
      if(anwser[maxPos].size() < anwser[i].size())
        maxPos = i;
    }
    cout << anwser[maxPos].size() << endl;
    for(deque<int>::iterator it = anwser[maxPos].begin(); it != anwser[maxPos].end(); it++)
    {
      cout << (*it) + 1 << " ";
    }
    cout << endl; 
  }
  return 0;
}
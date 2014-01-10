#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>

struct point
{
  double x, y;
};

struct vertex
{
  int c;
  int f;
  int back;
};

using namespace std;

deque<pair<int,vertex>>* verticies;//first куда течём, second ширина трубы и ширина потока
deque<pair<double, double>> dupla;
int* h;
int* e;
int s, n, b, r;

void PUSH(int u, int vIndex)
{
  int df = min(e[u], verticies[u][vIndex].second.c - verticies[u][vIndex].second.f);
  verticies[u][vIndex].second.f += df;
  verticies[verticies[u][vIndex].first][verticies[u][vIndex].second.back].second.f -= df;
  e[u] -= df;
  e[verticies[u][vIndex].first] += df;
}

void LIFT(int u)
{
  int minimal = INT_MAX;
  int len = verticies[u].size();
  for(int i = 0; i < len; i++)
  {
    if((verticies[u][i].second.c - verticies[u][i].second.f) > 0)
    {
      minimal = min(minimal, h[verticies[u][i].first]);
    }
  }
  h[u] = 1 + minimal;
}

void init_preflow()
{
  memset(h, 0, (s + n + 2) * sizeof(int));
  memset(e, 0, (s + n + 2) * sizeof(int));
  h[0] = s + n + 2;
  int len = verticies[0].size();
  for(int i = 0; i < len; i++)
  {
    verticies[0][i].second.f = verticies[0][i].second.c;
    verticies[verticies[0][i].first][verticies[0][i].second.back].second.f = -verticies[0][i].second.c;
    e[verticies[0][i].first] = verticies[0][i].second.c;
  }
};

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    scanf("%d %d %d %d", &s, &n, &b, &r);
    r *= r;
    verticies = new deque<pair<int,vertex>>[s + n + 2];
    h = new int[s + n + 2];
    e = new int[s + n + 2];
    vertex tmp;
    tmp.f = 0;
    for(int i = 0; i < s; i++)
    {
      double x, y;
      scanf("%lf %lf", &x, &y);
      dupla.push_back(make_pair(x, y));
      tmp.c = b;
      verticies[0].push_back(make_pair(i + 2, tmp));
      verticies[0][verticies[0].size() - 1].second.back = verticies[i + 2].size();
      tmp.c = 0;
      verticies[i + 2].push_back(make_pair(0, tmp));
      verticies[i + 2][verticies[i + 2].size() - 1].second.back = verticies[0].size() - 1;
    }
    for(int i = 0; i < n; i++)
    {
      double x, y;
      scanf("%lf %lf", &x, &y);
      for(int j = 0; j < s; j++)
      {
        if(((dupla[j].first - x) * (dupla[j].first - x) 
          + (dupla[j].second - y) * (dupla[j].second - y)) <= r )
        {
          tmp.c = 1;
          verticies[j + 2].push_back(make_pair(s + 2 + i, tmp));
          verticies[j + 2][verticies[j + 2].size() - 1].second.back = verticies[s + 2 + i].size();
          tmp.c = 0;
          verticies[s + 2 + i].push_back(make_pair(j + 2, tmp));
          verticies[s + 2 + i][verticies[s + 2 + i].size() - 1].second.back = verticies[j + 2].size() - 1;
        }
      }
      tmp.c = 1;
      verticies[s + 2 + i].push_back(make_pair(1, tmp));
      verticies[s + 2 + i][verticies[s + 2 + i].size() - 1].second.back = verticies[1].size();
      tmp.c = 0;
      verticies[1].push_back(make_pair(s + 2 + i, tmp));
      verticies[1][verticies[1].size() - 1].second.back = verticies[s + 2 + i].size() - 1;
    }
    dupla.clear();
    init_preflow();
    do
    {
      int i = 2;
      for(; i < s + n + 2; i++)
      {
        if(e[i] > 0)
          break;
      }
      if(i == s + n + 2)
      {
        break;
      }
      int j = 0;
      int len = verticies[i].size();
      for(; j < len; j++)
      {
        if(verticies[i][j].second.c - verticies[i][j].second.f > 0
            && (h[i] == (h[verticies[i][j].first] + 1)))
          break;
      }
      if(j != len)
      {
        PUSH(i, j);
      }
      else
      {
        LIFT(i);
      }
    }while(true);
    int answer = 0;
    for(int i = 0; i < s; i++)
    {
      answer += verticies[0][i].second.f;
    }
    printf("%d\n", answer);
  }
  return 0;
}
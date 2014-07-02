#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

struct building
{
  int x0, y0, x1, y1;
};

int w, h, b;
building buildings[1009];

void ReadData()
{
  scanf("%d %d %d", &w, &h, &b);
  for(int i = 0; i < b; i++)
  {
    scanf("%d %d %d %d", &buildings[i].x0, &buildings[i].y0, &buildings[i].x1, &buildings[i].y1);
    buildings[i].x1++;
    buildings[i].y1++;
  }
}

unsigned __int64 distances[1009];
unsigned __int64 matrix[1009][1009];
__int64 answer;
int start = 1007;
int finish = 1008;

__int64 calcDistance(int idx1, int idx2)
{
  __int64 d1, d2;
  if(buildings[idx2].x0 <= buildings[idx1].x1 && buildings[idx2].x1 >= buildings[idx1].x0)
  {
    d1 = 0;
  }
  else
  {
    d1 = buildings[idx1].x1 < buildings[idx2].x0
      ? buildings[idx2].x0 - buildings[idx1].x1
      : buildings[idx1].x0 - buildings[idx2].x1;
  }
  if(buildings[idx2].y0 <= buildings[idx1].y1 && buildings[idx2].y1 >= buildings[idx1].y0)
  {
    d2 = 0;
  }
  else
  {
    d2 = buildings[idx1].y1 < buildings[idx2].y0
      ? buildings[idx2].y0 - buildings[idx1].y1
      : buildings[idx1].y0 - buildings[idx2].y1;
  }
  return max(d1, d2);
}

void Solve()
{
  start = b, finish = b + 1;
  answer = 0;
  for(int i = 0; i < 1009; i++)
  {
    distances[i] = _I64_MAX;
  }
  distances[start] = 0;
  matrix[start][finish] = matrix[finish][start] = w;
  for(int i = 0; i < b; i++)
  {
    matrix[start][i] = matrix[i][start] = buildings[i].x0;
    matrix[finish][i] = matrix[i][finish] = w - buildings[i].x1;
    for(int j = 0; j < b; j++)
    {
      if(i == j)
      {
        matrix[i][i] = _I64_MAX;
        //continue;
      }
      else
      {
        matrix[i][j] = calcDistance(i, j);
      }
      //printf("%I64d ", matrix[i][j]);
    }
    //printf("\n");
  }
  set<pair<__int64, int>> s;
  set<pair<__int64, int>>::iterator it;
  for(int i = 0; i <= finish; i++)
  {
    s.insert(make_pair(distances[i], i));
  }
  while(!s.empty())
  {
    pair<__int64, int> current = *s.begin();
    s.erase(s.begin());
    for(int i = 0; i <= finish; i++)
    {
      if(current.first + matrix[current.second][i] < distances[i])
      {
        s.erase(make_pair(distances[i], i));
        distances[i] = current.first + matrix[current.second][i];
        s.insert(make_pair(distances[i], i));
      }
    }
  }
  answer = distances[finish];
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    printf("Case #%d: ", T + 1);
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
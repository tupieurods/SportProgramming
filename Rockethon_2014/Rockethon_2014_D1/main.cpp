#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct elem
{
  int x, y, l;
};

int n, m;
elem horiz[1009], vert[1009];

void ReadData()
{
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &vert[i].x, &vert[i].y, &vert[i].l);
  }
  for(int i = 0; i < m; i++)
  {
    scanf("%d %d %d", &horiz[i].x, &horiz[i].y, &horiz[i].l);
  }
}

bool between(int l, int r, int value)
{
  return value > l && value < r;
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(between(horiz[j].x, horiz[j].x + horiz[j].l, vert[i].x)
        && between(vert[i].y, vert[i].y + vert[i].l, horiz[j].y))
      {
        answer = max(answer, min(abs(vert[i].y - horiz[j].y),
          min(abs(vert[i].y + vert[i].l - horiz[j].y),
          min(abs(horiz[j].x - vert[i].x), abs(horiz[j].x + horiz[j].l - vert[i].x)))));
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
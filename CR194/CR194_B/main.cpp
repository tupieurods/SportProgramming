#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

set<int> xS, yS;
set<pair<int, int>> dots;

void ReadData()
{
  xS.clear();
  yS.clear();
  dots.clear();
  for(int i = 0; i < 8; i++)
  {
    int l, r;
    scanf("%d %d", &l, &r);
    xS.insert(l);
    yS.insert(r);
    dots.insert(make_pair(l, r));
  }
}

bool answer;

void Solve()
{
  answer = true;
  if(xS.size() != 3 || yS.size() != 3 || dots.size() != 8)
  {
    answer = false;
    return;
  }
  set<int>::iterator itX = xS.begin();
  set<int>::iterator itY;
  for(int i = 0; i < 3; i++)
  {
    itY = yS.begin();
    for(int j = 0; j < 3; j++)
    {
      if(i == 1 && j == 1)
      {
        if(dots.find(make_pair(*itX, *itY)) != dots.end())
        {
          answer = false;
          return;
        }
      }
      else
      {
        if(dots.find(make_pair(*itX, *itY)) == dots.end())
        {
          answer = false;
          return;
        }
      }
      itY++;
    }
    itX++;
  }
}

void WriteData()
{
  if(answer)
    printf("respectable\n");
  else
    printf("ugly\n");
}

int main()
{
  int QWE = 1;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
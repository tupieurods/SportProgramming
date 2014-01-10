#include <stdio.h>
#include <set>

std::set<std::pair<int, int>> dots, vert, horiz;
bool answer;

void ReadData()
{
  dots.clear();
  vert.clear();
  horiz.clear();
  for(int i = 0; i < 4; i++)
  {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
    {
      dots.insert(std::make_pair(x1, y1));
      dots.insert(std::make_pair(x2, y2));
      if(x1 == x2)
      {
        horiz.insert(std::make_pair(x1, y1));
        horiz.insert(std::make_pair(x2, y2));
      }
      else if(y1 == y2)
      {
        vert.insert(std::make_pair(x1, y1));
        vert.insert(std::make_pair(x2, y2));
      }
    }
  }
}

void Solve()
{
  answer = false;
  if(dots.size() == 4 && vert.size() == 4 && horiz.size() == 4)
    answer = true;
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
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
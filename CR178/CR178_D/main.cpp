#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

#pragma warning(disable: 4996)

int n, m;
int xPos, yPos, dx, dy;
char str[9];

void ReadData()
{
  scanf("%d %d", &n, &m);
  scanf("%d %d %s%*c", &yPos, &xPos, str);
}

__int64 answer;

void Solve()
{
  //If you want understand this solution
  //just draw some test case on the list of paper
  dy = str[0] == 'D' ? 1 : -1;
  dx = str[1] == 'R' ? 1 : -1;
  if(dy == 1 && yPos == n || dy == -1 && yPos == 1)
  {
    dy *= -1;
  }
  if(dx == 1 && xPos == m || dx == -1 && xPos == 1)
  {
    dx *= -1;
  }
  answer = 1;
  std::set<std::pair<int, int>> s;
  s.insert(std::make_pair(xPos, yPos));
  for(int i = 0; i < 2 * (m + n); i++)
  {
    int factor = std::min(std::abs(yPos - (dy == 1 ? n : 1)), std::abs(xPos - (dx == 1 ? m : 1)));
    answer += factor;
    yPos += factor * dy;
    xPos += factor * dx;
    std::pair<int, int> current = std::make_pair(xPos, yPos);
    s.insert(current);
    if(yPos == 1 || yPos == n)
    {
      dy *= -1;
    }
    if(xPos == 1 || xPos == m)
    {
      dx *= -1;
    }
    if(s.size() == (n + m - 2))
    {
      return;
    }
  }
  answer = -1;
}

void WriteData()
{
  printf("%I64d\n", answer);
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
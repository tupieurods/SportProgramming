#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int tw, th, w, h;

void ReadData()
{
  scanf("%d %d %d %d", &tw, &th, &w, &h);
}

bool answer;

int gcd(int a, int b, int &_x, int &_y)
{
  if(a == 0)
  {
    _x = 0;
    _y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b % a, a, x1, y1);
  _x = y1 - (b / a) * x1;
  _y = x1;
  return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
  g = gcd(a, b, x0, y0);
  if(c % g != 0)
  {
    return false;
  }
  x0 *= c / g;
  y0 *= c / g;
  if(x0 < 0 && y0 < 0)
  {
    return false;
  }
  int lx = -x0 / b;//-x0 * g / b actually
  int ly = y0 / a;//y00 * g / a actually
  //no g mul, because, it's useless for comparison
  if(x0 % b != 0)
  {
    lx++;
  }
  if(lx > ly)
  {
    return false;
  }
  return true;
}

void Solve()
{
  answer = true;
  if(w % tw == 0 && h % th == 0)
  {
    return;
  }
  if(h % tw == 0 && w % th == 0)
  {
    return;
  }
  int x0, y0, g;
  if(h % tw == 0 && h % th == 0 && find_any_solution(tw, th, w, x0, y0, g))
  {
    return;
  }
  if(w % tw == 0 && w % th == 0 && find_any_solution(tw, th, h, x0, y0, g))
  {
    return;
  }
  answer = false;
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
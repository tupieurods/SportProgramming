#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

inline int min(int a, int b)
{
  return a < b ? a : b;
}

inline int max(int a, int b)
{
  return a > b ? a : b;
}

inline bool check(int value)
{
  return (value % 2) == 0;
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d\n", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
    x1 = check(y1) ? x1 * 2 : x1 * 2 - 1;
    x2 = check(y2) ? x2 * 2 : x2 * 2 - 1;
    int dx = abs(x1 - x2);
    int minY = y1 - dx;
    int maxY = y1 + dx;
    int answer = dx;
    if(!((y2 >= minY) && (y2 <= maxY)))
    {
      int dy = min(abs(y2 - minY), abs(maxY - y2));
      answer += dy / 2;
    }
    printf("Case %d: %d\n", T + 1, answer);
  }
  return 0;
}
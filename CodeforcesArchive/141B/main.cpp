#include <stdio.h>

int a, x, y;
int answer;

void ReadData()
{
  scanf("%d %d %d", &a, &x, &y);
}

int abs(int val)
{
  return val < 0 ? -val : val;
}

void Solve()
{
  answer = -1;
  if(abs(x) >= a || y % a == 0)
  {
    return;
  }
  int line = y / a;
  //один квадратик
  if(line == 0 || line % 2 == 1)
  {
    if(abs(x) >= (double)a / 2.0)
      return;
    if(line != 0)
    {
      answer = 2 + 3 * ((line - 1) / 2);
    }
    else
    {
      answer = 1;
    }
    return;
  }
  //два квадратика
  if(x == 0)
    return;
  answer = 2 + 3 * ((line - 2) / 2);
  answer += x < 0 ? 1 : 2;
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int X1, Y1, X2, Y2;

void ReadData()
{
  scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
  if(X1 > X2 || Y1 > Y2)
  {
    std::swap(X1, X2);
    std::swap(Y1, Y2);
  }
}

bool answer;
int X3, Y3, X4, Y4;

void Solve()
{
  answer = false;
  if(X1 == X2)
  {
    answer = true;
    int d = Y2 - Y1;
    X3 = X1 + d;
    X4 = X1 + d;
    Y3 = Y1;
    Y4 = Y2;
  }
  else if(Y1 == Y2)
  {
    answer = true;
    int d = X2 - X1;
    Y3 = Y1 + d;
    Y4 = Y1 + d;
    X3 = X1;
    X4 = X2;
  }
  else
  {
    int d1 = abs(X2 - X1);
    int d2 = abs(Y2 - Y1);
    if(d1 == d2)
    {
      answer = true;
      Y3 = Y2;
      X3 = X1;
      Y4 = Y1;
      X4 = X2;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("%d %d %d %d\n", X3, Y3, X4, Y4);
  }
  else
  {
    printf("-1\n");
  }
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
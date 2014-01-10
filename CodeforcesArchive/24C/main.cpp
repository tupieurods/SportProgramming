#include <stdio.h>

struct point
{
  int x, y;
};

point M, *A;
int n;
__int64 j;

void ReadData()
{
  scanf("%d %I64d", &n, &j);
  scanf("%d %d", &M.x, &M.y);
  A = new point[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &A[i].x, &A[i].y);
  }
}

void Solve()
{
  j = j % (2 * n);
  for(int i = 0; i < j; i++)
  {
    int index = i % n;
    M.x = 2 * A[index].x - M.x;//Because newX = 2 * (A[index].x - oldX) + oldX;
    M.y = 2 * A[index].y - M.y;
  }
}

void WriteData()
{
  printf("%d %d\n", M.x, M.y);
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
#include <stdio.h>

int a[4];
bool canTriangle, canSegment;

void ReadData()
{
  scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
}

int steps[4][3] =
{
  {1, 2, 3},
  {0, 2, 3},
  {0, 1, 3},
  {0, 1, 2}
};

void Solve()
{
  canTriangle = false;
  canSegment = false;
  for(int i = 0; i < 4; i++)
  {
    int sum = a[steps[i][0]] + a[steps[i][1]];
    int sum2 = a[steps[i][0]] + a[steps[i][2]];
    int sum3 = a[steps[i][1]] + a[steps[i][2]];
    if(sum > a[steps[i][2]] 
      && sum2 > a[steps[i][1]]
      && sum3 > a[steps[i][0]])
      canTriangle = true;
    if(sum == a[steps[i][2]] 
      || sum2 == a[steps[i][1]]
      || sum3 == a[steps[i][0]])
      canSegment = true;
  }
}

void WriteData()
{
  if(canTriangle)
  {
    printf("TRIANGLE\n");
  }
  else if(canSegment)
  {
    printf("SEGMENT\n");
  }
  else
  {
    printf("IMPOSSIBLE\n");
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
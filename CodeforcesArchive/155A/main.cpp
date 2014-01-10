#include <stdio.h>

int n;

int answer;

void ReadData()
{
  answer = 0;
  int minimal, maximal;
  scanf("%d", &n);
  scanf("%d", &minimal);
  maximal = minimal;
  for(int i = 1; i < n; i++)
  {
    int current;
    scanf("%d", &current);
    if(current > maximal)
    {
      answer++;
      maximal = current;
    }
    if(current < minimal)
    {
      answer++;
      minimal = current;
    }
  }
}

void Solve()
{
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
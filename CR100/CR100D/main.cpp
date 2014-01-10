#include <stdio.h>
#include <stdlib.h>

int n;
int *a;
int answerCount, answer;

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void ReadData()
{
  scanf("%d", &n);
  a = new int[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), compare);
}

void Solve()
{
  int time = -350;
  for(int i = 0; i < n; i++)
  {
    time += a[i];
    if(time <= 360)
    {
      answerCount++;
      if(time > 0)
      {
        answer += time;
      }
      continue;
    }
    break;
  }
}

void WriteData()
{
  printf("%d %d\n", answerCount, answer);
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
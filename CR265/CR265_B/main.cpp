#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
int a[1009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    if(a[i] == 1)
    {
      if(answer == 0)
      {
        answer++;
      }
      else if(a[i - 1] == 1)
      {
        answer++;
      }
      else
      {
        answer += 2;
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
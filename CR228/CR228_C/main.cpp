#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int a[109];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  { 
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
}

int current[109];

bool check(int t)
{
  int check = n - 1;
  for(int i = 0; i < t; i++)
  {
    current[i] = a[check];
    check--;
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < t; j++)
    {
      if(check == -1)
      {
        return true;
      }
      if(current[j] != 0)
      {
        current[j] = min(current[j] - 1, a[check]);
        check--;
      }
    }
  }
  return check == -1;
}

int answer;

void Solve()
{
  int l = 1, r = n;
  for(; l <= r; l++)
  {
    if(check(l))
    {
      answer = l;
      break;
    }
  }
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
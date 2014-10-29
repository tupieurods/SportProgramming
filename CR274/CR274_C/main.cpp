#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
pair<int, int> ex[5009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &ex[i].first, &ex[i].second);
  }
}

int answer;

void Solve()
{
  sort(ex, ex + n);
  int currentDay = min(ex[0].first, ex[0].second);
  answer = currentDay;
  for(int i = 1; i < n; i++)
  {
    if(currentDay <= ex[i].second)
    {
      currentDay = ex[i].second;
    }
    else
    {
      currentDay = ex[i].first;
    }
    answer = currentDay;
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
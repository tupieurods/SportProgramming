#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>

using namespace std;

int n;
set<int> used;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 1; i <= 200009; i++)
  {
    used.insert(i);
  }
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(val > 0)
    {
      int answer = *(used.lower_bound(val));
      printf("%d\n", answer);
      used.erase(answer);
    }
    else
    {
      used.insert(-val);
    }
  }
}

void WriteData()
{
  printf("\n");
}

int main()
{
  int QWE = 1;
  freopen("floor4.in", "r", stdin);
  #ifndef ONLINE_JUDGE
  scanf("%d", &QWE);
  #else
  freopen("floor4.out", "w", stdout);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
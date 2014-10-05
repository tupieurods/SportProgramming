#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int n;
int a[100009];
set<int> s;

void ReadData()
{
  scanf("%d", &n);
  memset(a, 0xFF, sizeof(a));
  for(int i = 0; i < n; i++)
  {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    a[v1] = v2;
    s.insert(v2);
  }
}

bool answer;

void Solve()
{
  answer = false;
  for(int i = 1; i <= n; i++)
  {
    if(a[i] != -1)
    {
      set<int>::iterator it = s.find(a[i]);
      if(s.begin() != it)
      {
        answer = true;
        return;
      }
      s.erase(a[i]);
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("Happy Alex\n");
  }
  else
  {
    printf("Poor Alex\n");
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

pair<int, int> a[100009], b[100009];
int n;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    a[i].first = v1, a[i].second = i;
    b[i].first = v2, b[i].second = i;
  }
}

bool ans[100009][2];

void Solve()
{
  sort(a, a + n);
  sort(b, b + n);
  memset(ans, 0, sizeof(ans));
  int ind1 = 0, ind2 = 0, cnt = 0;
  for(int i = 0; i < n; i++)
  {
    if(a[ind1].first < b[ind2].first)
    {
      ans[a[ind1].second][0] = true;
      ind1++;
    }
    else
    {
      ans[b[ind2].second][1] = true;
      ind2++;
    }
  }
  int k = n / 2;
  for(int i = 0; i < k; i++)
  {
    ans[a[i].second][0] = true;
    ans[b[i].second][1] = true;
  }
}

void WriteData()
{
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("%d", ans[j][i] ? 1 : 0);
    }
    printf("\n");
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
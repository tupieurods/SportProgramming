#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

using namespace std;

int n, m, k;
bool a[309];
int np, p1, p2;

void ReadData()
{
  scanf("%d %d %d", &n, &m, &k);
  memset(a, 0, sizeof(a));
  np = -1;
  p1 = -1;
  p2 = -1;
  for(int i = 0; i < k; i++)
  {
    int val;
    scanf("%d", &val);
    val--;
    a[val] = true;
    if(i == 0)
    {
      p1 = val;
    }
    else if(i == 1)
    {
      p2 = val;
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i] == false)
    {
      np = i;
      return;
    }
  }
}

bool answer;
vector<pair<int, int>> v;

void Solve()
{
  answer = true;
  if(k == n)
  {
    answer = false;
    return;
  }
  /*if(k == n || (2 * n - k - 2 + ((n - 1) * (n - 2)) / 2) < m)
  {
    answer = false;
    return;
  }*/
  v.clear();
  v.push_back(make_pair(p1, np));
  v.push_back(make_pair(p2, np));
  for(int i = 0; i < n; i++)
  {
    if(i != p1 && i != p2 && i != np)
    {
      v.push_back(make_pair(p1, i));
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(i == p1 || i == p2)
    {
      continue;
    }
    for(int j = i + 1; j < n; j++)
    {
      if(j == p1 || j == p2)
      {
        continue;
      }
      v.push_back(make_pair(i, j));
    }
  }
  for(int i = 0; i < n; i++)
  {
    if(a[i] == false && i != np)
    {
      v.push_back(make_pair(p2, i));
    }
  }
}

void WriteData()
{
  if(!answer || v.size() < m)
  {
    printf("-1\n");
  }
  else
  {
    for(int i = 0; i < m; i++)
    {
      printf("%d %d\n", v[i].first + 1, v[i].second + 1);
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
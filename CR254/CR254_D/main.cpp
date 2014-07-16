#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, d;
__int64 X;
int a[100009], b[100009], c[100009];

//x - это 64-битная переменная
int getNextX()
{
  X = (X * 37 + 10007) % 1000000007;
  return X;
}

void initAB()
{
  int i;
  for(i = 0; i < n; i = i + 1)
  {
    a[i] = i + 1;
  }
  for(i = 0; i < n; i = i + 1)
  {
    std::swap(a[i], a[getNextX() % (i + 1)]);
  }
  for(i = 0; i < n; i = i + 1)
  {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for(i = 0; i < n; i = i + 1)
  {
    std::swap(b[i], b[getNextX() % (i + 1)]);
  }
}

void ReadData()
{
  scanf("%d %d %I64d", &n, &d, &X);
}

void Solve()
{
  initAB();
  set<pair<int, int>> s;
  vector<int> v;
  memset(c, 0, sizeof(c));
  for(int i = 0; i < n; i++)
  {
    if(b[i] == 1)
    {
      v.push_back(i);
    }
    s.insert(make_pair(-a[i], i));
    if(v.size() == 0)
    {
      continue;
    }
    int j = 0;
    for(set<pair<int, int>>::iterator it = s.begin(); it != s.end() && j < 30; it++, j++)
    {
      if(b[i - it->second] == 1)
      {
        c[i] = -it->first;
        break;
      }
    }
    if(c[i] == 0)
    {
      for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
      {
        c[i] = max(c[i], a[i - *it]);
      }
    }
  }
  //printf("test\n");
}

void WriteData()
{
  for(int i = 0; i < n; i++)
  {
    printf("%d\n", c[i]);
  }
  printf("\n");
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
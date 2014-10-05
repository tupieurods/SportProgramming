#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

int n, a, b;
set<pair<int, int>> s;

void ReadData()
{
  scanf("%d %d %d", &n, &a, &b);
  s.clear();
  for(int i = 0; i < n; i++)
  {
    pair<int, int> p;
    scanf("%d", &p.first);
    p.second = i;
    s.insert(p);
  }
}

bool answer;
int c[100009];
bool swapped;

void Solve()
{
  answer = true;
  memset(c, 0xFF, sizeof(c));
  swapped = false;
  if(a < b)
  {
    swapped = true;
    swap(a, b);
  }
  while(s.size() != 0)
  {
    pair<int, int> p = *s.begin();
    if(c[p.second] != -1)
    {
      throw;
    }
    int d = a - p.first;
    set<pair<int, int>>::iterator it = s.lower_bound(make_pair(d, -1));
    if(it == s.end() || it->first > d)
    {
      int d = b - p.first;
      it = s.lower_bound(make_pair(d, -1));
      if(s.end() == it || it->first > d)
      {
        answer = false;
        return;
      }
      c[it->second] = 1;
      c[p.second] = 1;
      if(it->first == p.first)
      {
        s.erase(s.begin());
      }
      else
      {
        s.erase(s.begin());
        s.erase(it);
      }
    }
    else
    {
      c[it->second] = 0;
      c[p.second] = 0;
      if(it->first == p.first)
      {
        s.erase(s.begin());
      }
      else
      {
        s.erase(s.begin());
        s.erase(it);
      }
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
    for(int i = 0; i < n; i++)
    {
      printf("%d ", swapped ? 1 - c[i] : c[i]);
    }
    printf("\n");
  }
  else
  {
    printf("NO\n");
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
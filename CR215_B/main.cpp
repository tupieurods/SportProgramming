#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
int answers[100009], a[100009];
map<int, int> elems;
map<int, int>::iterator it;

void ReadData()
{
  scanf("%d %d", &n, &m);
  elems.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    it = elems.find(a[i]);
    if(it == elems.end())
    {
      elems.insert(make_pair(a[i], 1));
    }
    else
    {
      it->second++;
    }
  }
}

void Solve()
{
  for(int i = 0; i < n; i++)
  {
    answers[i] = elems.size();
    it = elems.find(a[i]);
    if(it->second == 1)
    {
      elems.erase(it);
    }
    else
    {
      it->second--;
    }
  }
}

void WriteData()
{
  for(int i = 0; i < m; i++)
  {
    int l;
    scanf("%d", &l);
    printf("%d\n", answers[l - 1]);
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
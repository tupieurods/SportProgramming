#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

int n;
__int64 k;
int a[100009];
map<int, int> m;
map<int, int>::iterator it;

void ReadData()
{
  scanf("%d %I64d", &n, &k);
  m.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    it = m.find(a[i]);
    if(it == m.end())
    {
      m.insert(make_pair(a[i], 1));
    }
    else
    {
      it->second++;
    }
  }
}

int compare(const void *v1, const void *v2)
{
  return (*(int*)v1 - *(int*)v2);
}

int l, r;

void Solve()
{
  qsort(a, n, sizeof(int), compare);
  r = 0;
  int ind = (k - 1)/ n;
  l = a[ind];
  ind = 0;
  while(a[ind] != l)
  {
    ind++;
  }
  k -= n * 1LL * ind;
  if(k == 0)
  {
    r = m.begin()->first;
    return;
  }
  map<int, int>::iterator wtf;
  wtf = m.find(l);
  for(it = m.begin(); it != m.end(); it++)
  {
    k -= it->second * 1LL * wtf->second;
    /*if(it->first == l)
    {
      k -= it->second * 1LL * it->second;
    }
    else
    {
      k -= it->second;
    }*/
    if(k <= 0)
    {
      r = it->first;
      break;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", l, r);
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
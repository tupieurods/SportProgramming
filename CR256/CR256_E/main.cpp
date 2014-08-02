#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

__int64 X, k;
map<__int64, vector<__int64>> m;

void ReadData()
{
  scanf("%I64d %I64d", &X, &k);
}

int N = 100000;

void generate(__int64 Xval)
{
  if(m.find(Xval) != m.end())
  {
    return;
  }
  vector<__int64> v;
  for(__int64 i = 1; i * i <= Xval; i++)
  {
    if(Xval % i == 0)
    {
      v.push_back(i);
      if(i * i != Xval)
      {
        v.push_back(Xval / i);
      }
    }
  }
  sort(v.begin(), v.end());
  m.insert(make_pair(Xval, v));
}

void f(__int64 Xval, __int64 kval)
{
  if(N == 0)
  {
    return;
  }
  if(kval == 0 || Xval == 1)
  {
    printf("%I64d ", Xval);
    N--;
    return;
  }
  generate(Xval);
  map<__int64, vector<__int64>>::iterator itM = m.find(Xval);
  for(vector<__int64>::iterator itV = itM->second.begin(); itV != itM->second.end(); itV++)
  {
    f(*itV, kval - 1);
    if(N == 0)
    {
      return;
    }
  }
}

void Solve()
{
  //m.clear();
  f(X, k);
}

void WriteData()
{
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
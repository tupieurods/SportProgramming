#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

//#define LOCAL

using namespace std;

set<string> w, l;
set<string>::iterator it;
int n;

void ReadData()
{
  #ifdef LOCAL
  w.clear();
  l.clear();
  #endif
  cin >> n;
}

void Solve()
{
  string first, second;
  for(int i = 1; i < n; i++)
  {
    cin >> first;
    cin >> second;
    it = w.find(second);
    if(it != w.end())
    {
      w.erase(it);
    }
    l.insert(second);
    it = l.find(first);
    if(it == l.end() && w.find(first) == w.end())
    {
      w.insert(first);
    }
  }
}

void WriteData()
{
  if(w.size() != 1)
  {
    throw;
  }
  cout << *(w.begin()) << endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  cin >> QWE;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
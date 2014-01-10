using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A_CSharp
{
  class Program
  {
    BigInt

    private static void ReadData()
{
  cin >> n;
  current = 1LL;
  for(int i = 0; i < n; i++)
  {
    string name;
    int k;
    cin >> name;
    cin >> k;
    options.insert(make_pair(name, make_pair(k, true)));
    current *= k;
  }
  cin >> w >> h >> p;
}

    static void Main(string[] args)
    {
      ReadData();
      Solve();
    }
  }
}

/*#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

int n, m;
map<string, pair<int, bool>> options;
__int64 w, h;
__int64 p;
__int64 current;
void WriteData()
{
  if(current == 0LL)
  {
    cout << "shit" << endl;
    return;
  }
  if(p / current < 10LL)
  {
    cout << "Slideshow" << endl;
  }
  else if(p / current >= 60LL)
  {
    cout << "Perfect" << endl;
  }
  else
  {
    cout << "So-so" << endl;
  }
}

void Solve()
{
  current *= w;
  current *= h;
  WriteData();
  cin >> m;
  string first, second;
  map<string, pair<int, bool>>::iterator it;
  for(int i = 0; i < m; i++)
  {
    cin >> first;
    if(first == "Off" || first == "On")
    {
      cin >> second;
      it = options.find(second);
      if(it == options.end())
        throw;
      it->second.second = !it->second.second;
      if(it->second.second)
      {
        current *= it->second.first;
      }
      else
      {
        current /= it->second.first;
      }
    }
    else//Resolution
    {
      __int64 nW, nH;
      cin >> nW >> nH;
      current /= w;
      current /= h;
      current *= nW;
      current *= nH;
      w = nW;
      h = nH;
    }
    WriteData();
  }
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  cin >> QWE;
  #endif
  __int64 test = 1LL;
  for(int i = 0; i < 100000; i++)
  {
    test *= 100;
  }
  test *= 2560 * 1600;
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    //WriteData();
  }
  return 0;
}*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;



int main()
{
  ifstream strm("input.txt");
  int n, m;
  strm >> n >> m;
  char first = 'B', 
    second = 'G';
  if(n<m)
  {
    swap(n, m);
    swap(first, second);
  }
  bool flag = false;
  //ofstream cout("output.txt");
  while((n != 0) || (m != 0))
  {
    if(m == 0)
      flag = false;
    if(flag)
    {
      cout << second;
      m--;
    }
    else
    {
      n--;
      cout << first;
    }
    flag = !flag;
  }
  strm.close();
  //cout.close();
  return 0;
}
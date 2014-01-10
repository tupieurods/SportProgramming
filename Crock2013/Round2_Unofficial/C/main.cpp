#include <iostream>
#include <string>

using namespace std;

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int n;
  cin >> n;
  string str1, str2;
  cin >> str1;
  cin >> str2;
  int f = 0, s = 0, same = 0;
  int dF = 0, dS = 0;
  for(int i = 0; i < 2 * n; i++)
  {
    if(str1[i] == '1' && str2[i] == '1')
    {
      same++;
      if((same) % 2 != 0)
      {
        f++;
      }
      else
      {
        s++;
      }
    }
    else
    {
      if(str1[i] == '1')
        dF++;
      if(str2[i] == '1')
        dS++;
    }
  }
  int minimal = min(dS, dF);
  f += minimal;
  s += minimal;
  //cout << f << " " << s << endl;
  dS -= minimal;
  dF -= minimal;
  if(dF != 0 || dS != 0)
  {
    int step = (same % 2 == 0) ? 1 : 0;
    if(dF > 0)
    {
      while(dF != 0)
      {
        //cout << step << endl;
        if(step % 2 == 1)
          f++;
        step++;
        dF--;
      }
    }
    else if(dS > 0)
    {
      while(dS != 0)
      {
        if(step % 2 == 0)
          s++;
        step++;
        dS--;
      }
    }
  }
  //cout << f << " " << s << endl;
  if(f > s)
  {
    cout << "First" << endl;
  }
  else if(s > f)
  {
    cout << "Second" << endl;
  }
  else
  {
    cout << "Draw";
  }
  return 0;
}

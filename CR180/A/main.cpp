#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  string str;
  cin >> str;
  bool flag = true;
  for(int i = 0; i < n; i++)
  {
    if(str[i] != '.')
    {
      int s = i + 1;
      int t = i;
      while(str[t] != 'L' && str[t] != '.')
        t++;
      if(t != i)
        t++;
      cout << s << " " << t;
      return 0;
    }
  }
  return 0;
}

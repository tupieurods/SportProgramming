#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  int pos = 0;
  bool flag = true;
  while(pos < n - 1)
  {
    int delta = 1;
    while(str[pos + delta] != '.')
      delta++;
    if(delta > k)
    {
      flag = false;
      break;
    }
    pos += delta;
  }
  if(flag)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}

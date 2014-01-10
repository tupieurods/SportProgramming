#include <iostream>

using namespace std;

int main()
{
  string str;
  for(int i = 0; i < 8; i++)
  {
    cin >> str;
    int current = 0;
    int success = (((i + 1) % 2) == 1) ? 85 : 170;
    for(int j = 0; j < 8; j++)
    {
      current <<= 1;
      if(str[j] == 'B')
        current |= 1;
    }
    bool flag = true;
    for(int j = 0; j < 8; j++)
    {
      if(current == success)
      {
        flag = false;
        break;
      }
      int tmp = current & 1;
      current >>= 1;
      current |= tmp << 7;
    }
    if(flag)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}

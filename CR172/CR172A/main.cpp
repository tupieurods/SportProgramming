#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;
  char c = str[0];
  if(c <= 'z' && c  >= 'a')
    c = c - 'a' + 'A';
  str[0] = c;
  cout << str;
  return 0;
}

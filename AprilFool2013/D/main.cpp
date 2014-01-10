#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;
  int num;
  cin >> num;
  num += 97;
  for(int i = 0; i < str.length(); i++)
  {
    char c = str[i];
    if(c <= 'Z')
      c = c - 'A' + 'a';
    if(c > 'Z' && c < (char)num)
    {
      c = c - 'a' + 'A';
    }
    str[i] = c;
  }
  cout << str << endl;
  return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str1, str2;
  cin >> str1;
  cin >> str2;
  if(str1.length() != str2.length())
  {
    cout << "NO";
    return 0;
  }
  if((str1 == str2)
    || str1.find("01") != str1.npos
    || str1.find("10") != str1.npos
    || str1.find("11") != str1.npos)
  {
    if(str2.find("1") == str2.npos && str1.find("1") != str1.npos)
      cout << "NO";
    else
      cout <<"YES";
    return 0;
  }
  cout << "NO";
  return 0;
}

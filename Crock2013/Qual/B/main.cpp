#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  string str;
  while(getline(cin, str))
  {
    int pos = 0;
    int len = str.length();
    /*while(str.at(pos) == ' ')
      pos++;*/
    while(pos < len)
    {
      while(pos < len && str.at(pos) == ' ')
        pos++;
      if(pos >= len)
        break;
      int from;
      if(str.at(pos) == '\"')
      {
        from = pos + 1;
        do
        {
          pos++;
        }while(str.at(pos) != '\"');
      }
      else
      {
        from = pos;
        do
        {
          pos++;
          if(pos >= len)
          {
            break;
          }
        }while(str.at(pos) != ' ');
      }
      pos++;
      //cout << from << " " << pos << "\n";
      cout << '<' << str.substr(from, pos - from - 1) << ">\n";
    }
  }
  cout << endl;
  return 0;
}
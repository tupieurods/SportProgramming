#include <iostream>
//#include <stdio.h>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  //scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    string ip;
    cin >> ip;
    string left = "";
    string right = "";
    string tmp = "";
    for(int j = 0; j < ip.length(); j++)
    {
      if(ip[j] != ':')
        tmp += ip[j];
      else
      {
        if(tmp == "")
        {
          tmp = "LLLL";
        }
        else
        {
          tmp = string(4 - tmp.length(), '0') + tmp;
        }
        left += tmp + ":";
        tmp = "";
      }
    }
    left += string(4 - tmp.length(), '0') + tmp;
    cout << left + right << endl;
  }
  return 0;
}

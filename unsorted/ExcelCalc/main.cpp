#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

string toStr(int value)
{
  std::stringstream strStream;
  strStream << value;
  return strStream.str();
}

int main()
{
  int n;
  scanf("%d", &n);
  string *Result = new string[n+1];
  for(int i = 0; i <= n; i++)
    {
      Result[i] = "";
      string tmp;
      getline(std::cin, tmp);
      if(i == 0)
        continue;
      int a, b;
      if(sscanf(tmp.c_str(), "R%dC%d", &a, &b) == 2)
        {
          int divider = b;
          do
            {
              divider--;
              char tmpChar='A'+(divider%26);
              Result[i]=tmpChar+Result[i];
              divider/=26;
            }
          while(divider > 0);
          Result[i] += toStr(a);
        }
      else
        {
          int calcValue = 0;
          int j = 0;
          for(; ; j++)
            {
              if(tmp[j] >= '0' && tmp[j] <= '9')
                break;
              calcValue = calcValue * 26 + tmp[j] - 64;
            }
          Result[i] = "R" + tmp.substr(j) + "C" + toStr(calcValue);
        }
    }
  for(int i = 0; i <= n; i++)
    {
      if(Result[i] != "")
        printf("%s\n", Result[i].c_str());
    }
  return 0;
}

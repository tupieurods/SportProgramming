#include <iostream>
#include <stdio.h>
#include <string>
#include <set>

using namespace std;

int main()
{
  string str;
  getline(std::cin, str);

  set< pair<int, int> > swaps;
  int balance = 0;
  __int64 total = 0;

  for(int i = 0; i < str.size(); i++)
    {
      if(str[i] == '(')
        balance++;
      if(str[i] == ')')
        balance--;
      if(str[i] == '?')
        {
          int openBracket, closeBracket;
          scanf("%d %d", &openBracket, &closeBracket);
          total += closeBracket;
          str[i] = ')';
          balance--;
          swaps.insert(make_pair(openBracket - closeBracket, i));
        }
      if(balance == -1)
        {
          if(swaps.empty())
            break;
          str[swaps.begin()->second] = '(';
          total += swaps.begin()->first;
          balance += 2;
          swaps.erase(swaps.begin());
        }
    }

  if(balance != 0)
    printf("-1");
  else
    printf("%I64d\n%s", total, str.c_str());
  return 0;
}

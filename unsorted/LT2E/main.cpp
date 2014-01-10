#include <math.h>
#include <string>
#include <iostream>
#include <map>
#include <limits.h>

using namespace std;

struct symbol
{
  int data[2];
};

symbol getSymbol(int code)
{
  static map<int, symbol> cache;
  if(cache.count(code) == 0) //Уже считали для этого символа
  {
    symbol result;
    result.data[0] = 0;
    result.data[1] = 0;
    int tmp = code;
    do
    {
      result.data[tmp%2]++;
      tmp /= 2;
    } while(tmp != 0);
    result.data[0] += 8 - (result.data[0] + result.data[1]);
    cache.insert(make_pair(code, result));
  }
  return cache[code];
}

int main()
{
  string s;
  cin >> s;
  //cout<<(int)s[0];
  int inOne = 0;
  cin >> inOne;
  symbol result;
  result.data[0] = 0;
  result.data[1] = 0;
  for(string::iterator i = s.begin(); i != s.end(); i++)
  {
    symbol tmp = getSymbol((int) * i);
    result.data[0] += tmp.data[0];
    result.data[1] += tmp.data[1];
  }

  int len = s.length();
  int side=floor(sqrt(len));
  if(side*side<len)
    side++;
  result.data[0]=side*side*8-result.data[1];

  result.data[0] = result.data[0] % inOne == 0
                ? result.data[0] / inOne
                : (result.data[0] / inOne) + 1;

  result.data[1] = result.data[1] % inOne == 0
                   ? result.data[1] / inOne
                   : (result.data[1] / inOne) + 1;

  cout << result.data[0] << " " << result.data[1] << endl;
  return 0;
}

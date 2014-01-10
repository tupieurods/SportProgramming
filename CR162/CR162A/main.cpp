#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s, t;
  cin >> s;
  cin >> t;
  int current = 0;
  for(int i = 0; i < t.length(); i++)
  {
    if(s[current] == t[i])
      current++;
  }
  cout << current + 1;
  return 0;
}

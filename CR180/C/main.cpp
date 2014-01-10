#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a, b;
  cin >> a;
  cin >> b;
  int len = a.length();
  int parityA = 0;
  for(int i = 0; i < len; i++)
  {
    if(a[i] == '1')
      parityA++;
  }
  len = b.length();
  int parityB = 0;
  for(int i = 0; i < len; i++)
  {
    if(b[i] == '1')
      parityB++;
  }
  if(parityA % 2 == 1)
    parityA++;
  if(parityA < parityB)
  {
    cout << "NO";
  }
  else
  {
    cout << "YES";
  }
  return 0;
}

#include <iostream>

using namespace std;

int nod(int a, int b)
{
  if(a * b == 0)
    return a;
  return nod(b, a % b);
}

int main()
{
  int n;
  cin >> n;
  int anwser = 0;
  for(int i = 1; i <= n; i++)
  {
    if(nod(n, i) == 1)
      anwser++;
  }
  cout << anwser;
  return 0;
}

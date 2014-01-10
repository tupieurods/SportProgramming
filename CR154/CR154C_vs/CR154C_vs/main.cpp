#include <stdlib.h>
#include <iostream>

using namespace std;

#define LOCALTEST

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int QWE;
#ifdef LOCALTEST
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    cin >> n;
    int* data = new int[n];
    for(int i = 0; i < n; i++)
    {
      cin >> data[i];
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int delta = r1 > r2 ? -1 : +1;
    int result = 0;
    while(r1 != r2)
    {
      r1 += delta;
      result++;
      if(data[r1 - 1] < c1)
        c1 = data[r1 - 1];
    }
    result += abs(c2 - c1);
    cout << result << endl;
    delete data;
  }
  return 0;
}
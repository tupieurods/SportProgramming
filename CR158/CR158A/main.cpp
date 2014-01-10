#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    string awnser;
    int before = a;
    for(int i = 0; i < 10; i++)
    {
      if(((a * 10 + i) % b) == 0)
      {
        a = a * 10 + i;
        break;
      }
    }
    if(a == before)
    {
      cout << "-1" << endl;
      return 0;
    }
    cout << a;
    n--;
    for(int i = 0; i < n; i++)
    {
      cout << "0";
    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    size_t pos = str.find('0');
    if(pos == -1)
    {
      str.erase(str.size() - 1, 1);
    }
    else
    {
      str.erase(pos, 1);
    }
    cout << str << endl;
    return 0;
}

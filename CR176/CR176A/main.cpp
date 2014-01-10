#include <iostream>
#include <string>

using namespace std;

int data[4][4];

bool check()
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      int sum = data[i][j] + data[i][j + 1]
        + data[i + 1][j] + data[i + 1][j + 1];
      if(sum == 4 || sum == 0)
        return true;
    }
  }
  return false;
}

int main()
{
  string str;
  for(int i = 0; i < 4; i++)
  {
    cin >> str;
    for(int j = 0; j < 4; j++)
    {
      data[i][j] = str[j] == '.' ? 0 : 1;
    }
  }
  if(check())
  {
    cout << "YES\n";
    return 0;
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      data[i][j] ^= 1;
      if(check())
      {
        cout << "YES\n";
        return 0;
      }
      data[i][j] ^= 1;
    }
  }
  cout << "NO\n";
  return 0;
}

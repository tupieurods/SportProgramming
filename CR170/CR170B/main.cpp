#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <stdlib.h>

//Sami duraki

using namespace std;

int n;
string* data;

bool tryToGetAnswer(int k, string elem)
{
  if(k == 0)
  {
    for(int i = 0; i < n; i++)
    {
      if(data[i].find(elem) != data[i].npos)
      {
        return false;
      }
    }
    cout << elem << endl;
    return true;
  }
  char c;
  for(int i = 0; i < 26; i++)
  {
    c = ((char)i + 'a');
    string tmp = elem + c;
    if(tryToGetAnswer(k - 1, tmp))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> n;
  data = new string[n];
  bool* firstCheck = new bool[26];
  memset(firstCheck, 0, sizeof(bool) * 26);
  for(int i = 0; i < n; i++)
  {
    cin >> data[i];
    int len = data[i].length();
    for(int j = 0; j < len; j++)
    {
      firstCheck[(int)(data[i][j] - 'a')] = true;
    }
  }
  for(int i = 0; i < 26; i++)
  {
    if(!firstCheck[i])
    {
      cout << (char)(i + 'a');
      return 0;
    }
  }
  for(int k = 2; k <= 21; k++)
  {
    if(tryToGetAnswer(k, ""))
      return 0;
  }
  for(int i = 11; i < n; i++)
  {
    cout << data[i] << endl;
  }
  return 0;
}

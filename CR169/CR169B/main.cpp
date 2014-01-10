#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
  string str;
  cin >> str;
  int len = str.length();
  int arr[26];
  memset(arr, 0, 26 * sizeof(int));
  for(int i = 0; i < len; i++)
  {
    arr[(int)(str[i] - 'a')]++;
  }
  int answer = 0;
  for(int i = 0; i < 26; i++)
  {
    answer += arr[i] % 2;
  }
  if(answer == 0 || (len % 2 == 1))
  {
    cout << "First";
  }
  else
  {
    cout << "Second";
  }
  return 0;
}

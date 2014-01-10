#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
  string input;
  cin >> input;
  int count = input.length();
  int* anwser = new int[count];
  int left = 0;
  int right = count - 1;
  for(int i = 0; i < count; i++)
  {
    if(input[i] == 'l')
    {
      anwser[right--] = i + 1;
    }
    else
    {
      anwser[left++] = i + 1;
    }
  }
  for(int i = 0; i < count; i++)
  {
    cout << anwser[i] << endl;
  }
  return 0;
}

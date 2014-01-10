#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int p[3] = {0, 0, 0};
  string str;
  getline(std::cin, str);
  for(int i = 0; i < n; i++)
  {
    getline(std::cin, str);
    switch(str[0])
    {
      case 'E':
        p[0]++;
      break;
      case 'L':
        p[1]++;
      break;
      case 'M':
        p[2]++;
      break;
    }
  }
  int maxi = 0;
  if(p[1] > p[maxi])
    maxi = 1;
  if(p[2] > p[maxi])
    maxi = 2;
  switch(maxi)
  {
    case 0:
      cout << "Emperor Penguin" << endl;
      break;
    case 1:
      cout << "Little Penguin" << endl;
      break;
    case 2:
      cout << "Macaroni Penguin" << endl;
      break;
  }
  return 0;
}
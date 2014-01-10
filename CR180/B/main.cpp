#include <iostream>
#include <string>

using namespace std;

int abs(int val)
{
  return val < 0 ? -val : val;
}

int main()
{
  int t, sX, sY, eX, eY;
  cin >> t >> sX >> sY >> eX >> eY;
  string str;
  cin >> str;
  char c1 = eX > sX ? 'E' : 'W',
    c2 = eY > sY ? 'N' : 'S';
  int dx = abs(eX - sX);
  int dy = abs(eY - sY);
  int cnt1 = 0, cnt2 = 0;
  int arriveX = -1, arriveY = -1;
  for(int i = 0; i < t; i++)
  {
    if(str[i] == c1)
      cnt1++;
    if(cnt1 == dx && arriveX == -1)
      arriveX = i + 1;
    if(str[i] == c2)
      cnt2++;
    if(cnt2 == dy && arriveY == -1)
      arriveY = i + 1;
  }
  if(cnt1 >= dx && cnt2 >= dy)
    cout << max(arriveX, arriveY);
  else
    cout << -1;
  return 0;
}

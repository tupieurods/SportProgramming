#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <string>

using namespace std;

//#define LOCALTEST

struct point
{
  int x, y;
};

bool operator ==(const point& a,const point& b)
{
  return ((a.x == b.x) && (a.y == b.y));
}

bool operator <(const point& a,const point& b)
{
  return ((a.x * 1000000 + a.y) < (b.x * 1000000 +b.y));
}

float distance(point a)
{
  float x = (float)a.x / 1000;
  float y = (float)a.y / 1000;
  return 
  min(sqrt(x * x + y * y),
    min(sqrt((x - 1) * (x - 1) + y * y),
      min(sqrt(x * x + (y - 1) * (y - 1)),
        sqrt((x - 1) * (x - 1) + (y - 1) * (y - 1)))));
}

void parse(string str, int& first, int& second)
{
  int index = -1;
  int parsed = 0;
  bool minus = false;
  while(true)
  {
    index++;
    if(str[index] == '-')
    {
      minus = true;
      continue;
    }
    if(str[index] != '.')
    {
      continue;
    }
    if(parsed == 0)
    {
      first = ((int)str[index + 1] - '0') * 100 +((int)str[index + 2] - '0') * 10 + ((int)str[index + 3] - '0');
      parsed = 1;
      index += 4;
      if(minus && first != 0)
        first = 1000 - first;
      minus = false;
    }
    else
    {
      second = ((int)str[index + 1] - '0') * 100 +((int)str[index + 2] - '0') * 10 + ((int)str[index + 3] - '0');
      if(minus && second != 0)
        second = 1000 - second;
      break;
    }
  }
}

int main()
{
  int QWE;
#ifdef LOCALTEST
  freopen("input.txt", "r", stdin);
  cin >> QWE;
#else
  QWE = 1;
#endif
  for(int T = 0; T < QWE; T++)
  {
    int n;
    cin >> n;
    map<point, int> distances;
    map<point, int>::iterator it;
    string str;
    getline(cin, str);
    for(int i = 0; i < n; i++)
    {
      float x, y;
      getline(cin, str);
      point tmp;
      parse(str, tmp.x, tmp.y);
      it = distances.find(tmp);
      if(it != distances.end())
      {
        it->second++;
      }
      else
      {
        distances.insert(make_pair(tmp, 1));
      }
    }

    int count = 0;
    float min = 10000;
    for(it = distances.begin(); it!=distances.end(); it++)
    {
      float minDist = distance(it->first);
      if((it->second == count) && (minDist - min <= 0.000001))
      {
        min = minDist;
        count = it->second;
      }
      else if(it->second > count)
      {
        min = minDist;
        count = it->second;
      }
    }
    cout << count << " " << setprecision(10) << fixed << min << endl;
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
//#define LOCAL

struct point
{
  int x, y;
};

int n;
point points[109];
int numbers[109];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d %d", &points[i + 1].x, &points[i + 1].y, &numbers[i + 1]);
  }
  points[0] = points[n];
  numbers[0] = numbers[n];
  points[n + 1] = points[1];
  numbers[n + 1] = numbers[1];
}

string answer;

int cross(point &v1, point &v2, point &v3, point &v4)
{
  int x1 = v2.x - v1.x,
    x2 = v4.x - v3.x,
    y1 = v2.y - v1.y,
    y2 = v4.y - v3.y;
  return x1 * y2 - x2 * y1;
}

int dot(point &v1, point &v2, point &v3, point &v4)
{
  int x1 = v2.x - v1.x,
    x2 = v4.x - v3.x,
    y1 = v2.y - v1.y,
    y2 = v4.y - v3.y;
  return x1 * x2 + y1 * y2;
}

bool myCheck(string v1, string v2)
{
  //printf("check: %s %s\n", v1.c_str(), v2.c_str());
  int len = v1.length();
  if(len != v2.length())
  {
    throw;
  }
  for(int i = 0; i < len; i++)
  {
    if(v1[i] != v2[i])
    {
      return v1[i] < v2[i];
    }
  }
  return true;
}

void Solve()
{
  answer = "";
  string current = "Q";
  int last = 1;
  for(int i = 1; i <= n; i++)
  {
    current.erase(current.begin());
    //current.push_back('0' + (char)numbers[last]);
    while(true)
    {
      int vectorMulLen = cross(points[i], points[i + 1], points[last], points[last + 1]);
      if(vectorMulLen < 0)
      {
        break;
      }
      if(vectorMulLen == 0)
      {
        if(dot(points[i], points[i + 1], points[last], points[last + 1]) < 0)
        {
          break;
        }
      }
      current.push_back('0' + (char)numbers[last]);
      last++;
      if(last > n)
      {
        last = 1;
      }
    }
    if((current.length() > answer.size())
      || (current.length() == answer.size() && myCheck(answer, current)))
    {
      answer = current;
    }
  }
}

void WriteData()
{
  printf("%s\n", answer.c_str());
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  ReadData();
  Solve();
  WriteData();
  return 0;
}
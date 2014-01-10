#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

__int64 answer;
int T;
double l, r;

void ReadData()
{
  scanf("%lf %lf", &l, &r);
  //printf("%lf %lf", l, r);
}


bool check(double val)
{
  if(val - floor(val) > 0.0001)
    return false;
  val = floor(val);
  std::ostringstream ss;
  ss << val;
  string str = ss.str();
  string str2 = str.substr(0);
  reverse(str.begin(), str.end());
  //printf("%lf:%s %s\n", val, str.c_str(), str2.c_str());
  return str.find(str2) == 0;
}

void Solve()
{
  answer = 0;
  for(double i = l; i <= r; i++)
  {
    
    if(/*i * i <= r &&*/ check(i) && check(sqrt(i)))
    {
      answer++;
      //printf("%lf\n", i);
    }
  }
}

void WriteData()
{
  printf("Case #%d: %I64d\n", T + 1, answer);
}

int main()
{
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
#include <stdio.h>
#include <math.h>
#include <stack>

using namespace std;

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  double val;
  stack<double> s;
  while(scanf("%lf", &val) != EOF)
  {
    s.push(val);
  }
  while(!s.empty())
  {
    printf("%.10lf\n", sqrt(s.top()));
    s.pop();
  }
  return 0;
}
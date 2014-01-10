#include <stdio.h>
#include <deque>
#include <algorithm>

using namespace std;

int n, x;
bool hasX;
deque<int> a;

void ReadData()
{
  scanf("%d %d", &n, &x);
  hasX = false;
  a.clear();
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    a.push_back(val);
    if(val == x)
      hasX = true;
  }
  if(!hasX)
  {
    a.push_back(x);
    n++;
  }
}

int answer;
void Solve()
{
  answer = hasX ? 0 : 1;
  sort(a.begin(), a.end());
  while(a[(n + 1) / 2 - 1] != x)
  {
    if(a[(n + 1) / 2 - 1] > x)
      a.push_front(1);
    else
      a.push_back(1);
    answer++;
    n++;
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, xp, yp;

void ReadData()
{
  scanf("%d %d %d %d", &n, &m, &xp, &yp);
  xp--;
  yp--;
}

vector<__int64> answer;

void add(int xpos, int ypos)
{
  __int64 value = (ypos * 1LL * (ypos - 1)) / 2LL;
  if(xpos < ypos)
  {
    value -= ((ypos - xpos - 1) * 1LL * (ypos - xpos)) / 2LL;
  }
  if(value != 0)
  {
    answer.push_back(value);
  }
  __int64 value2 = ypos * 1LL * xpos;
  value2 -= value + min(xpos, ypos);
  if(value2 != 0)
  {
    answer.push_back(value2);
  }
}

void Solve()
{
  answer.clear();
  add(xp, yp);
  add(n - 1 - xp, yp);
  add(n - 1 - xp, m - 1 - yp);
  add(xp, m - 1 - yp);
}

void WriteData()
{
  printf("%d ", answer.size());
  if(answer.size() != 0)
  {
    sort(answer.begin(), answer.end());
    for(vector<__int64>::iterator it = answer.begin(); it != answer.end(); it++)
    {
      printf("%I64d ", *it);
    }
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
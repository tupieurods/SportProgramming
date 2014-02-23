#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int answer[2];

void ReadData()
{
  v.clear();
  answer[0] = 0;
  answer[1] = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    int s;
    scanf("%d", &s);
    int center = s % 2 == 0 ? s / 2 : s / 2 + 1;
    int ind = 0;
    for(int j = 1; j <= s; j++)
    {
      int value;
      if(j == center)
      {
        if(s % 2 == 1)
        {
          scanf("%d", &value);
          v.push_back(value);
          ind = 1;
          continue;
        }
      }
      scanf("%d", &value);
      answer[ind] += value;
      if(j == center)
      {
        ind = 1;
      }
    }
  }
}

void Solve()
{
  sort(v.begin(), v.end(), greater<int>());
  int ind = 0;
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
  {
    answer[ind] += *it;
    ind = (ind + 1) % 2;
  }
}

void WriteData()
{
  printf("%d %d\n", answer[0], answer[1]);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
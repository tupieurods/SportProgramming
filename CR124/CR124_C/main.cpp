#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[30];

void ReadData()
{
  char str[100009];
  scanf("%s%*c", str);
  for(int i = 0; i < 30; i++)
  {
    a[i].clear();
  }
  int n = strlen(str);
  for(int i = 0; i < n; i++)
  {
    a[(int)(str[i] - 'a')].push_back(i);
  }
}

char answer[100009];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  int index = -1;
  int n = 0;
  vector<int>::iterator it;
  for(char i = 'z'; i >= 'a'; i--)
  {
    if(a[(int)(i - 'a')].size() == 0)
      continue;
    it = lower_bound(a[(int)(i - 'a')].begin(), a[(int)(i - 'a')].end(), index);
    while(it != a[(int)(i - 'a')].end())
    {
      answer[n] = i;
      n++;
      index = *it;
      it++;
    }
  }
}

void WriteData()
{
  printf("%s\n", answer);
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
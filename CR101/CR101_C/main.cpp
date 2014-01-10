#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char names[3009][19];
int output[3009];
vector<pair<int, int>> a;

void ReadData()
{
  a.clear();
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%s", names[i]);
    int value;
    scanf("%d%*c", &value);
    a.push_back(make_pair(value, i));
    output[i] = 1;
  }
}

bool answer;

void Solve()
{
  sort(a.begin(), a.end());
  answer = false;
  int firstNonZero = 1;
  for(int i = 1; i < a.size(); i++)
  {
    if(a[i].first > i)
    {
      return;
    }
    int toIncrease = a[i].first - a[i - 1].first;
    if(toIncrease == 0)
    {
      continue;
    }
    for(int j = i - 1; j >= 0; j--)
    {
      if(output[j] != 1
        || toIncrease != 0)
      {
        output[j]++;
        if(output[j] == 2)
        {
          toIncrease--;
        }
      }
    }
  }
  answer = true;
}

void WriteData()
{
  if(answer == false)
  {
    printf("-1\n");
    return;
  }
  for(int i = 0; i < n; i++)
  {
    printf("%s %d\n", names[a[i].second], output[i]);
  }
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
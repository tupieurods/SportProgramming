#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#pragma warning(disable: 4996)

int n, k, p;
int odd[100009], even[100009];
int oddL, evenL;

void ReadData()
{
  scanf("%d %d %d", &n, &k, &p);
  oddL = evenL = 0;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(val % 2 == 1)
    {
      odd[oddL++] = val;
    }
    else
    {
      even[evenL++] = val;
    }
  }
}

vector<int> answer[100009];
bool answerExist;

void Solve()
{
#ifndef ONLINE_JUDGE
  for(int i = 0; i < n; i++)
  {
    answer[i].clear();
  }
#endif
  answerExist = false;
  for(int i = 0; i < p; i++)
  {
    if(evenL != 0)
    {
      answer[i].push_back(even[evenL - 1]);
      evenL--;
    }
    else if(oddL >= 2)
    {
      answer[i].push_back(odd[oddL - 1]);
      answer[i].push_back(odd[oddL - 2]);
      oddL -= 2;
    }
    else
    {
      return;
    }
  }
  if(p == 0)
  {
    if(oddL < k)
    {
      return;
    }
    for(int i = 0; i < k; i++)
    {
      answer[i].push_back(odd[oddL - 1]);
      oddL--;
    }
    if(oddL % 2 != 0)
    {
      return;
    }
    while(evenL != 0)
    {
      answer[0].push_back(even[evenL - 1]);
      evenL--;
    }
    while(oddL != 0)
    {
      answer[0].push_back(odd[oddL - 1]);
      oddL--;
    }
  }
  else
  {
    if(oddL < k - p)
    {
      return;
    }
    for(int i = p; i < k; i++)
    {
      answer[i].push_back(odd[oddL - 1]);
      oddL--;
    }
    if(oddL % 2 != 0)
    {
      return;
    }
    int idx = k == p ? 0 : p;
    while(evenL != 0)
    {
      answer[idx].push_back(even[evenL - 1]);
      evenL--;
    }
    while(oddL != 0)
    {
      answer[idx].push_back(odd[oddL - 1]);
      oddL--;
    }
  }
  answerExist = true;
}

void WriteData()
{
  if(!answerExist)
  {
    printf("NO\n\n");
    return;
  }
  printf("YES\n");
  for(int i = 0; i < k; i++)
  {
    printf("%d ", answer[i].size());
    for(vector<int>::iterator it = answer[i].begin(); it != answer[i].end(); ++it)
    {
      printf("%d ", *it);
    }
    printf("\n");
  }
  printf("\n");
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
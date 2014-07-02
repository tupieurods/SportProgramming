#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

//#define LOCAL

using namespace std;

int n, a, b;
vector<int> ans[100009];

void ReadData()
{
  scanf("%d %d %d", &n, &a, &b);
  for(int i = 0; i < n; i++)
  {
    ans[i].clear();
  }
}

bool answer;

void Solve()
{
  if(a >= n || b >= n)
  {
    answer = false;
    return;
  }
  answer = true;
  int pureDaughter = n - a;
  int idx0 = a - 1;
  int idx = n;
  while(idx0 >= 0 && pureDaughter > 0 && b > 0)
  {
    ans[idx0].push_back(idx);
    pureDaughter--;
    idx0--;
    if(idx0 == -1)
    {
      idx0 = 0;
    }
    idx--;
    b--;
  }
  /*if(pureDaughter != 0 || b < 0)
  {
    answer = false;
    return;
  }*/
  idx = 2;
  for(int i = 0; (i <= a - 2) && (b != 0); i++)
  {
    ans[i].push_back(idx);
    idx++;
    b--;
  }
  if(b != 0)
  {
    answer = false;
    return;
  }
  for(int i = 0; i < a; i++)
  {
    if(ans[i].size() == 0)
    {
      answer = false;
      return;
    }
  }
  for(int i = a; i < n; i++)
  {
    if(ans[i].size() != 0)
    {
      answer = false;
      return;
    }
  }
}

void WriteData()
{
  if(answer == false)
  {
    printf("IMPOSSIBLE\n");
  }
  else
  {
    for(int i = 0; i < n; i++)
    {
      printf("%d ", ans[i].size());
      for(vector<int>::iterator it = ans[i].begin(); it != ans[i].end(); it++)
      {
        printf("%d ", *it);
      }
      printf("\n");
    }
  }
}


int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    /*if(T == 156)
    {
      printf("check!\n");
    }*/
    ReadData();
    Solve();
    WriteData();
    /*if(T == 156)
    {
      return 0;
    }*/
  }
  return 0;
}
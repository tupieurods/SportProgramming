#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char str[100009];
int z[100009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

set<int> answer;
int ra[100009];

void Solve()
{
  answer.clear();
  memset(z, 0, sizeof(z));
  memset(ra, 0, sizeof(ra));
  int l = 0, r = 0;
  for(int i = 1; i < len; i++)
  {
    if(i <= r)
    {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < len && str[z[i]] == str[i + z[i]])
    {
      z[i]++;
    }
    if(i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
  //printf("stage1\n");
  int maximal = 0;
  for(int i = len - 1; i > 0; i--)
  {
    if(z[i] == len - i)
    {
      answer.insert(z[i]);
      maximal = z[i];
    }
  }
  for(int i = 1; i < len; i++)
  {
    //if(answer.find(z[i]) != answer.end())
    //{
      ra[z[i]]++;
    //}
  }
  int accum = 0;
  for(int i = len; i > 0; i--)
  {
    if(ra[i] != 0)
    {
      int toAdd = ra[i];
      ra[i] += accum;
      accum += toAdd;
    }
  }
  /*if(answer.find(1) != answer.end())
  {
    answer[1]++;
  } */
}

void WriteData()
{
  printf("%d\n", answer.size() + 1);
  for(set<int>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d %d\n", *it, ra[*it] + 1);
  }
  printf("%d %d\n\n", len, 1);
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
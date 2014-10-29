#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, l, f, s;
__int64 p[100009];
set<__int64> ps;

void ReadData()
{
  scanf("%d %d %d %d", &n, &l, &f, &s);
  ps.clear();
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &p[i]);
    ps.insert(p[i]);
  }
}

//only 2 items, but anyway
vector<int> answer;

bool checkfor(int value)
{
  if(ps.find(value) != ps.end())
  {
    return true;
  }
  for(int i = 0; i < n; i++)
  {
    if((ps.find(p[i] - value) != ps.end()) || (ps.find(p[i] + value) != ps.end()))
    {
      return true;
    }
  }
  return false;
}

void answerAdd(__int64 val)
{
  if(ps.find(val) == ps.end())
  {
    ps.insert(val);
    answer.push_back(val);
  }
}

void Solve()
{
  bool ff = checkfor(f);
  bool fs = checkfor(s);
  answer.clear();
  if(ff || fs)
  {
    if(ff && fs)
    {
      return;
    }
    if(ff)
    {
      answerAdd(s);
    }
    else
    {
      answerAdd(f);
    }
    return;
  }
  __int64 bigdaddy = f + s;
  for(int i = 0; i < n; i++)
  {
    if(ps.find(p[i] - bigdaddy) != ps.end())
    {
      answerAdd(p[i] - f);
      return;
    }
    if(ps.find(p[i] + bigdaddy) != ps.end())
    {
      answerAdd(p[i] + f);
      return;
    }
  }
  for(int i = 0; i < n; i++)
  {
    __int64 v = p[i] - f;
    /*if(v < 0)
    {
      continue;
    }*/
    if(v >= 0 && ps.find(v + s) != ps.end())
    {
      answerAdd(v);
      return;
    }
    v = p[i] + f;
    if(v <= l && (ps.find(v + s) != ps.end() || ps.find(v - s) != ps.end()))
    {
      answerAdd(v);
      return;
    }
  }
  answerAdd(s);
  answerAdd(f);
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<int>::iterator it = answer.begin(); it != answer.end(); ++it)
  {
    printf("%d ", *it);
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
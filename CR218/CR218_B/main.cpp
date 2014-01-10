#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>

int a_in, b_in;

using namespace std;

void ReadData()
{
  scanf("%d %d", &a_in, &b_in);
}

std::map<std::pair<int, int>, int> cache;
std::map<std::pair<int, int>, int>::iterator it;

int f(int a, int b)
{
  if(a == b)
  {
    return 0;
  }
  it = cache.find(make_pair(min(a, b), max(a, b)));
  if(it != cache.end())
  {
    return it->second;
  }
  int result = INT_MAX;
  int cntFail = 0;
  int cntTry = 0;
  int check = -1;
  //Copy paste gogogogo
  if(a % 2 == 0)
  {
    check = f(a / 2, b);
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(a % 3 == 0)
  {
    check = f(a - 2 * (a / 3), b);
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(a % 5 == 0)
  {
    check = f(a - 4 * (a / 5), b);
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(b % 2 == 0)
  {
    check = f(a, b / 2);
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(b % 3 == 0)
  {
    check = f(a, b - 2 * (b / 3));
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(b % 5 == 0)
  {
    check = f(a, b - 4 * (b / 5));
    cntTry++;
    if(check == -1)
    {
      cntFail++;
    }
    else
    {
      result = std::min(result, check);
    }
  }
  if(cntFail == cntTry)
  {
    result = -1;
  }
  else
  {
    result++;
  }
  cache.insert(make_pair(make_pair(min(a, b), max(a, b)), result));
  return result;
}

int answer;

void Solve()
{
  answer = f(a_in, b_in);
}

void WriteData()
{
  printf("%d\n", answer);
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
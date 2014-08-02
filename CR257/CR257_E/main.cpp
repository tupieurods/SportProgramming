#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;

void ReadData()
{
  scanf("%d", &n);
}

vector<pair<int, int>> answer;
bool used[100009];

bool isPrime(int val)
{
  for(int i = 2; i * 1LL * i < val; i++)
  {
    if(val % i == 0)
    {
      return false;
    }
  }
  return true;
}

void Solve()
{
  answer.clear();
  memset(used, 0, sizeof(used));
  for(int i = 3; i * 2 <= n; i++)
  {
    if(!used[i] && !isPrime(i))
    {
      continue;
    }
    int cnt = 0;
    for(int j = i; j <= n; j += i)
    {
      if(!used[j])
      {
        cnt++;
      }
    }
    if(cnt % 2 == 1 && cnt != 1)
    {
      used[i * 2] = true;
    }
    int f = -1;
    for(int j = i; j <= n; j += i)
    {
      if(!used[j])
      {
        used[j] = true;
        if(f == -1)
        {
          f = j;
        }
        else
        {
          answer.push_back(make_pair(f, j));
          f = -1;
        }
      }
    }
    if(cnt % 2 == 1 && cnt != 1)
    {
      used[i * 2] = false;
    }
  }
  int f = -1;
  for(int j = 2; j <= n; j += 2)
  {
    if(!used[j])
    {
      used[j] = true;
      if(f == -1)
      {
        f = j;
      }
      else
      {
        answer.push_back(make_pair(f, j));
        f = -1;
      }
    }
  }
}

void WriteData()
{
  printf("%d\n", answer.size());
  for(vector<pair<int, int>>::iterator it = answer.begin(); it != answer.end(); it++)
  {
    printf("%d %d\n", it->first, it->second);
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
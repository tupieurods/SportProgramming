#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

#pragma comment(linker, "/STACK:66777216")

int n, k;
int c[100009];
vector<int> tree[4 * 100009];
map<int, vector<int>> numbersPos;

void ReadData()
{
  for(int i = 0; i < 4 * 100009; i++)
  {
    tree[i].clear();
  }
  numbersPos.clear();
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &c[i]);
    if(numbersPos.find(c[i]) == numbersPos.end())
    {
      numbersPos.insert(make_pair(c[i], vector<int>()));
    }
    numbersPos[c[i]].push_back(i);
  }
}

vector<int>::iterator it1, it2;

void build(int l, int r, int index)
{
  if(l == r)
  {
    tree[index].push_back(c[r]);
    return;
  }
  int center = l + (r - l) / 2;
  build(l, center, index * 2 + 1);
  build(center + 1, r, index * 2 + 2);
  it1 = tree[index * 2 + 1].begin();
  it2 = tree[index * 2 + 2].begin();
  while(it1 != tree[index * 2 + 1].end() || it2 != tree[index * 2 + 2].end())
  {
    if(it1 != tree[index * 2 + 1].end() && it2 != tree[index * 2 + 2].end())
    {
      if(*it1 < *it2)
      {
        tree[index].push_back(*it1);
        it1++;
      }
      else
      {
        tree[index].push_back(*it2);
        it2++;
      }
    }
    else if(it1 != tree[index * 2 + 1].end())
    {
      tree[index].push_back(*it1);
      it1++;
    }
    else
    {
      tree[index].push_back(*it2);
      it2++;
    }
  }
}

void addElem(int l, int r, int pos, int index, int value)
{
  if(l == r && pos == l)
  {
    tree[index].push_back(value);
    return;
  }
  int center = l + (r - l) / 2;
  if(pos <= center)
  {
    addElem(l, center, pos, index * 2 + 1, value);
  }
  else
  {
    addElem(center + 1, r, pos, index * 2 + 2, value);
  }
  it1 = tree[index * 2 + 1].begin();
  it2 = tree[index * 2 + 2].begin();
  tree[index].clear();
  while(it1 != tree[index * 2 + 1].end() || it2 != tree[index * 2 + 2].end())
  {
    if(it1 != tree[index * 2 + 1].end() && it2 != tree[index * 2 + 2].end())
    {
      if(*it1 < *it2)
      {
        tree[index].push_back(*it1);
        it1++;
      }
      else
      {
        tree[index].push_back(*it2);
        it2++;
      }
    }
    else if(it1 != tree[index * 2 + 1].end())
    {
      tree[index].push_back(*it1);
      it1++;
    }
    else
    {
      tree[index].push_back(*it2);
      it2++;
    }
  }
}

int findElem(int tl, int tr, int l, int r, int index, int val)
{
  if(l > r)
  {
    return INT_MAX;
  }
  if(tl == l && tr == r)
  {
    it1 = upper_bound(tree[index].begin(), tree[index].end(), val);
    return it1 == tree[index].end() ? INT_MAX : *it1;
  }
  int center = tl + (tr - tl) / 2;
  return min(findElem(tl, center, l, min(center, r), index * 2 + 1, val),
    findElem(center + 1, tr, max(center + 1, l), r, index * 2 + 2, val));
}

int dp[100009];

int f(int level)
{
  if(dp[level] != -1)
  {
    return dp[level];
  }
  if(level == n - 1)
  {
    return n - 1;
  }
  int result = level;
  int t = findElem(0, n - 1, level + 1, min(level + k, n - 1), 0, c[level]);
  int ind = -1;
  if(numbersPos.find(t) != numbersPos.end())
  {
    it1 = upper_bound(numbersPos[t].begin(), numbersPos[t].end(), min(level + k, n - 1));
    it1--;
    ind = *it1;
  }
  if(ind != -1)
  {
    result = max(result, f(ind));
  }
  dp[level] = result;
  return result;
}

int answer;

void Solve()
{
  build(0, n - 1, 0);
  answer = -1;
  memset(dp, 0xFF, sizeof(dp));
  for(int i = 0; i < k; i++)
  {
    answer = max(f(i), answer);
  }
}

void WriteData()
{
  printf("%d\n", answer + 1);
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
    //time_t timeTotal = clock();
    ReadData();
    Solve();
    WriteData();
    //printf("working time: %f\n", (float)timeTotal / CLOCKS_PER_SEC);
  }
  return 0;
}
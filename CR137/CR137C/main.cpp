#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int *sieveTable;

void generateSieveTable()
{
  sieveTable = new int[10000009];
  memset(sieveTable, 0, sizeof(int) * 10000009);
  for(int i = 2; i <= 10000000; i++)
  {
    if(sieveTable[i] == 0)
    {
      sieveTable[i] = i;
      if((__int64)i * i < 10000009)
      {
        for(int j = i * i; j < 10000009; j += i)
        {
          if(sieveTable[j] == 0)
          {
            sieveTable[j] = i;
          }
        }
      }
    }
  }
}

vector <int> a, b;
int *aFactorized, *bFactorized;
set<int> aFactors;

void ReadData()
{
  a.clear();
  b.clear();
  //aFactors.clear();
  scanf("%d %d", &n, &m);
  //a = new int[n];
  aFactorized = new int[10000009];
  memset(aFactorized, 0, sizeof(int) * 10000009);
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d", &val);
    if(val == 1) continue;
    //a[i] = val;
    a.push_back(val);
    while(sieveTable[val] != 0)
    {
      aFactors.insert(sieveTable[val]);
      aFactorized[sieveTable[val]]++;
      val /= sieveTable[val];
    }
    if(val > 1)
    {
      aFactors.insert(sieveTable[val]);
      aFactorized[val]++;
    }
  }
  n = a.size();
  //b = new int[m];
  bFactorized = new int[10000009];
  memset(bFactorized, 0, sizeof(int) * 10000009);
  for(int i = 0; i < m; i++)
  {
    int val;
    scanf("%d", &val);
    if(val == 1) continue;
    //b[i] = val;
    b.push_back(val);
    while(sieveTable[val] != 0)
    {
      bFactorized[sieveTable[val]]++;
      val /= sieveTable[val];
    }
    if(val > 1)
      bFactorized[val]++;
  }
  m = b.size();
}

void Solve()
{
  for(set<int>::iterator it = aFactors.begin(); it != aFactors.end(); it++)
  {
    int minimal = min(aFactorized[*it], bFactorized[*it]);
    aFactorized[*it] -= minimal;
    bFactorized[*it] -= minimal;
  }
  for(int i = 0; i < n; i++)
  {
    int restore = a[i];
    while(sieveTable[a[i]] != 0)
    {
      int del = sieveTable[a[i]];
      a[i] /= del;
      if(aFactorized[del] != 0)
      {
        aFactorized[del]--;
        //restore *= del;
      }
      else
      {
        restore /= del;
      }
    }
    a[i] = restore;
  }
  for(int i = 0; i < m; i++)
  {
    int restore = b[i];
    while(sieveTable[b[i]] != 0)
    {
      int del = sieveTable[b[i]];
      b[i] /= del;
      if(bFactorized[del] != 0)
      {
        bFactorized[del]--;
        //restore *= del;
      }
      else
      {
        restore /= del;
      }
    }
    b[i] = restore;
  }
}

void WriteData()
{
  if(n == 0)
  {
    a.push_back(1);
    n = 1;
  }
  if(m == 0)
  {
    m = 1;
    b.push_back(1);
  }
  printf("%d %d\n", n, m);
  for(vector<int>::iterator it = a.begin(); it !=  a.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n");
  for(vector<int>::iterator it = b.begin(); it !=  b.end(); it++)
  {
    printf("%d ", *it);
  }
  printf("\n");
}

int main()
{
  int QWE;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
#else
  QWE = 1;
#endif
  generateSieveTable();
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
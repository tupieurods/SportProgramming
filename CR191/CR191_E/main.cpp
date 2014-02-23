#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

#pragma warning(disable : 4996)

using namespace std;

const int MOD = 1000000007;
int n, k, a[30], kVals[2];
__int64 fact[25];
int powersOf3[13];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++)
  {
    scanf("%d", &kVals[i]);
  }
}

__int64 calcBadCnt(int val)
{
  __int64 result = 0;
  int center = n / 2 + n % 2;
  map<__int64, map<int, int>> sums[2];
  int conf[2];
  pair<int, int> ranges[2];
  conf[0] = 1 << center;
  conf[1] = 1 << (n - center);
  ranges[0] = make_pair(1, center);
  ranges[1] = make_pair(center + 1, n);
  for(int T = 0; T < 2; T++)
  {
    for(int mask = 0; mask < conf[T]; mask++)
    {
      int copy = mask;
      int cnt = 0, index = 0;
      __int64 currentSum = 0;
      while(copy != 0)
      {
        if((copy & 1) != 0)
        {
          currentSum += a[ranges[T].first - 1 + index];
          cnt++;
        }
        index++;
        copy >>= 1;
      }
      sums[T][currentSum][cnt]++;
    }
  }
  for(map<__int64, map<int, int>>::iterator it = sums[0].begin(); it != sums[0].end(); it++)
  {
    if(it->first > val)
    {
      break;
    }
    __int64 toSearch = val - it->first;
    if(sums[1].find(toSearch) != sums[1].end())
    {
      for(map<int, int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
      {
        for(map<int, int>::iterator it3 = sums[1][toSearch].begin(); it3 != sums[1][toSearch].end(); it3++)
        {
          int counter = it2->first + it3->first;
          int mul = it2->second * it3->second;
          __int64 factMul = (fact[counter] * fact[n - counter]) % MOD;
          result = (result + mul * factMul) % MOD;
        }
      }
    }
  }
  return result;
}

int mask3[15];

void addToMask()
{
  int toAdd = 1;
  int index = 0;
  while(toAdd != 0)
  {
    mask3[index] = mask3[index] + toAdd;
    if(mask3[index] == 3)
    {
      mask3[index] = 0;
      toAdd = 1;
    }
    else
    {
      toAdd = 0;
    }
    index++;
  }
}

__int64 calcIntersect()
{
  __int64 result = 0;
  int center = n / 2 + n % 2;
  map<pair<__int64, __int64>, map<pair<int, int>, int>> sums[2];
  pair<int, int> ranges[2];
  ranges[0] = make_pair(1, center);
  ranges[1] = make_pair(center + 1, n);
  for(int T = 0; T < 2; T++)
  {
    memset(mask3, 0, sizeof(mask3));
    mask3[0] = -1;
    pair<__int64, __int64> currentSum;
    pair<int, int> cnt;
    int cntElems = ranges[T].second - ranges[T].first + 1;
    for(int i = 0; i < powersOf3[cntElems]; i++)
    {
      addToMask();
      currentSum.first = 0;
      currentSum.second = 0;
      cnt.first = 0;
      cnt.second = 0;
      for(int j = 0; j < cntElems; j++)
      {
        switch(mask3[j])
        {
          case 0:
            currentSum.first = (currentSum.first + a[ranges[T].first - 1 + j]);
            cnt.first++;
            break;
          case 1:
            currentSum.second = (currentSum.second + a[ranges[T].first - 1 + j]);
            cnt.second++;
            break;
          default:
            break;
        }
      }
      sums[T][currentSum][cnt]++;
    }
  }
  for(map<pair<__int64, __int64>, map<pair<int, int>, int>>::iterator it = sums[0].begin(); it != sums[0].end(); it++)
  {
    if(it->first.first > kVals[0] || it->first.second > (kVals[1] - kVals[0]))
    {
      continue;
    }
    pair<__int64, __int64> toSearch = make_pair(kVals[0] - it->first.first, (kVals[1] - kVals[0]) - it->first.second);
    if(sums[1].find(toSearch) != sums[1].end())
    {
      for(map<pair<int, int>, int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
      {
        for(map<pair<int, int>, int>::iterator it3 = sums[1][toSearch].begin(); it3 != sums[1][toSearch].end(); it3++)
        {
          int counter1 = it2->first.first + it3->first.first;
          int counter2 = it2->first.second + it3->first.second;
          int mul = it2->second * it3->second;
          __int64 factMul1 = (fact[counter1] * fact[counter2]) % MOD;
          result = (result + ((mul * factMul1) % MOD) * fact[n - counter1 - counter2]) % MOD;
        }
      }
    }
  }
  return result;
}

__int64 answer;

void Solve()
{
  answer = fact[n];
  if(k == 0)
  {
    return;
  }
  if(k == 2)
  {
    if(kVals[0] > kVals[1])
    {
      swap(kVals[0], kVals[1]);
    }
    else if(kVals[0] == kVals[1])
    {
      k = 1;
    }
  }
  for(int i = 0; i < k; i++)
  {
    __int64 val = calcBadCnt(kVals[i]);
    answer -= val;
    if(answer < 0)
    {
      answer += MOD;
    }
  }
  if(k == 1)
  {
    return;
  }
  answer = (answer + calcIntersect()) % MOD;
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  fact[0] = 1;
  fact[1] = 1;
  for(int i = 2; i <= 24; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  powersOf3[0] = 1;
  powersOf3[1] = 3;
  for(int i = 2; i < 13; i++)
  {
    powersOf3[i] = powersOf3[i - 1] * 3;
  }
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
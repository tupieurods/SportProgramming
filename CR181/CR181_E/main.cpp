#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

int k, maximal;
__int64 cnt[10000009];
int sieve[10000009];
std::vector<int> primes;
__int64 totalSum;

void ReadData()
{
  memset(cnt, 0, sizeof(cnt));
  scanf("%d", &k);
  totalSum = 0;
  maximal = -1;
  for(int i = 0; i < k; i++)
  {
    int val;
    scanf("%d", &val);
    cnt[val]++;
    totalSum += val;
    maximal = std::max(maximal, val);
  }
}

__int64 XextentInNfact(__int64 fact, int x)
{
  __int64 result = 0;
  while(fact != 0)
  {
    fact /= x;
    result += fact;
  }
  return result;
}

bool check(__int64 current)
{
  for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
  {
    if(cnt[*it] == 0)
    {
      continue;
    }
    if(XextentInNfact(current, *it) < cnt[*it])
    {
      return false;
    }
  }
  return true;
}

__int64 answer;

void Solve()
{
  for(int i = maximal; i >= 2; i--)
  {
    cnt[i - 1] += cnt[i];
  }
  for(int i = maximal; i > 1; i--)
  {
    if(sieve[i] != i)
    {
      cnt[sieve[i]] += cnt[i];
    }
    cnt[i / sieve[i]] += cnt[i];
  }
  __int64 l = 1LL, r = totalSum;
  while(l < r)
  {
    __int64 center = l + (r - l) / 2LL;
    if(check(center))
    {
      r = center;
    }
    else
    {
      l = center + 1;
    }
  }
  answer = r;
}

void WriteData()
{
  printf("%I64d\n", answer);
}

int main()
{
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    printf("1\n100000\n");
    for(int i = 0; i < 100000; i++)
    {
      printf("100000 ");
    }
    return 0;
  }
  //calcSieve begin
  memset(sieve, 0xFF, sizeof(sieve));
  for(int current = 2; current <= 10000000; current++)
  {
    if(sieve[current] != -1)
    {
      continue;
    }
    primes.push_back(current);
    for(int v = current; v <= 10000000; v += current)
    {
      sieve[v] = current;
    }
  }
  //calcSieve end
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
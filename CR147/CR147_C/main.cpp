#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;
const int SieveSize = 1000009;
bool sieve[SieveSize];

void CalcSieve()
{
  memset(sieve, true, sizeof(sieve));
  sieve[0] = sieve[1] = false;
  for(int i = 2; i * i < SieveSize; i++)
  {
    if(sieve[i])
    {
      if(i * 1LL * i < SieveSize)
      {
        for(int j = i * i; j < SieveSize; j += i)
        {
          sieve[j] = false;
        }
      }
    }
  }
}

int a, b, k;
void ReadData()
{
  scanf("%d %d %d", &a, &b, &k);
  primes.clear();
  for(int i = a; i <= b; i++)
  {
    if(sieve[i])
      primes.push_back(i);
  }
}

int answer;
void Solve()
{
  answer = -1;
  if(k > primes.size())
  {
    return;
  }
  answer = max(b - primes[primes.size() - k] + 1, primes[k - 1] - a + 1);
  int cnt = primes.size() - k + 1;
  /*if(k == 1)
  {
    cnt--;
    for(int i = 0; i < cnt; i++)
    {
      answer = max(answer, primes[i + 1] - primes[i]);
    }
    return;
  }*/
  for(int i = 0; i < cnt; i++)
  {
    /*int test = primes[primes.size() - i - 1] - primes[primes.size() - i - k];
    int l = primes.size() - i - 1;*/
    int r = primes.size() - i - k - 1;
    if(r >= 0)
      answer = max(answer,
        primes[primes.size() - i - 1] - primes[r]);
  }
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
  CalcSieve();
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
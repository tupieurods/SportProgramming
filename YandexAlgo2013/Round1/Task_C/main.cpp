#define LOCAL
#include <stdio.h>
#include <vector>
#include <algorithm>

#ifndef LOCAL
#include <inttypes.h>
#define __int64 int64_t
#endif

using namespace std;

bool sieve[40009];
vector<int> primes;

void initSieve()
{
  memset(sieve, 1, sizeof(sieve));
  for(int i = 2; i < 40009; i++)
  {
    if(sieve[i])
    {
      sieve[i] = false;
      primes.push_back(i);
      if(i * 1LL * i < 40009)
      {
        for(int j = i * i; j < 40009; j += i)
        {
          sieve[j] = false;
        }
      }
    }
  }
}

int main()
{
  initSieve();
  int QWE;
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    __int64 n;
    int k;
    scanf("%lld %d", &n, &k);
    int answer = 0;
    for(int i = 0; n > 1 && primes[i] < 32000; i++)
    {
      while(n % primes[i] == 0)
      {
        answer++;
        n /= primes[i];
      }
    }
    if(n > 1)
      answer++;
    if(answer == k)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}
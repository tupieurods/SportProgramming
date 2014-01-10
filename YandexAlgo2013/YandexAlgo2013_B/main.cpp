#include <stdio.h>
#include <string.h>
#include <vector>
#include <inttypes.h>
#include <algorithm>

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

vector<int64_t> v; 

int main()
{
  initSieve();
  for(int i = 0; i < primes.size(); i++)
  {
    for(int j = i; j < primes.size(); j++)
    {
      v.push_back(primes[i] * 1LL * primes[j] + 1LL);
    }
  }
  sort(v.begin(), v.end());
  //printf("%d\n", s.size());
  int n;
  scanf("%d", &n);
  vector<int64_t>::iterator it;
  for(int i = 1; i <= n; i++)
  {
    int64_t val = i * 1LL * i;
    it = lower_bound(v.begin(), v.end(), val);
    if(*it == val)
    {
      printf("%d\n", i);
    }
  }
  return 0;
}
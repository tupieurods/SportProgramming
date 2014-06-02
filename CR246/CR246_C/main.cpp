#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[100009], b[100009];
vector<int> primes;
bool sieve[100009];

void ReadData()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
    b[a[i]] = i;
  }
}

vector<pair<int, int>> answer;
vector<int>::iterator itPrime;

void Solve()
{
  answer.clear();
  for(int i = n; i > 1; i--)
  {
    int delta = i - b[i] + 1;
    if(delta == 1)
    {
      continue;
    }
    while(delta != 1)
    {
      itPrime = lower_bound(primes.begin(), primes.end(), delta);
      if(*itPrime > delta)
      {
        itPrime--;
      }
      int b1 = b[i], b2 = b[i] - 1 + *itPrime;
      answer.push_back(make_pair(b1, b2));
      b[a[b1]] = b2;
      b[a[b2]] = b1;
      swap(a[b1], a[b2]);
      delta = delta - *itPrime + 1;
    }
  }
  for(int i = 1; i <= n; i++)
  {
    if(a[i] != i)
    {
      printf("PE\n");
      exit(0);
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
  memset(sieve, 1, sizeof(sieve));
  sieve[0] = sieve[1] = false;
  for(int i = 2; i < 100009; i++)
  {
    if(sieve[i])
    {
      primes.push_back(i);
      if(i * 1LL * i < 100009)
      {
        for(int j = i * i; j < 100009; j += i)
        {
          sieve[j] = false;
        }
      }
    }
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
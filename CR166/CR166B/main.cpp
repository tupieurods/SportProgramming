#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

bool* primes;
int n, m;

void calcPrimes()
{
  primes[0] = true;
  primes[1] = true;

  for(__int64 i = 2; i < 200000; i++)
  {
    if(!primes[i])
    {
       for(__int64 j = i * i; j < 200000; j += i)
        primes[j] = true;
    }
  }
}

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  primes = new bool[200000];
  memset(primes, false, sizeof(bool) * 200000);
  calcPrimes();
  set<int> primesSet;
  for(int i = 0; i < 200000; i++)
  {
    if(!primes[i])
      primesSet.insert(i);
  }
  scanf("%d %d", &n, &m);
  int** data = new int*[n];
  for(int i = 0; i < n; i++)
  {
    data[i] = new int[m];
    for(int j = 0; j < m; j++)
    {
      scanf("%d", &data[i][j]);
      data[i][j] = *primesSet.lower_bound(data[i][j]) - data[i][j];
    }
  }
  int anwser = 0x7F7F7F7F;
  for(int i = 0; i < n; i++)
  {
    int current = 0;
    for(int j = 0; j < m; j++)
    {
      current += data[i][j];
    }
    anwser = min(anwser, current);
  }
  for(int i = 0; i < m; i++)
  {
    int current = 0;
    for(int j = 0; j < n; j++)
    {
      current += data[j][i];
    }
    anwser = min(anwser, current);
  }
  printf("%d", anwser);
  return 0;
}

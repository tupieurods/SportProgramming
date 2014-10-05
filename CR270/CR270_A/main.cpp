#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

bool prime[1000009];
int n;

void ReadData()
{
  scanf("%d", &n);
}

int answer;

void Solve()
{
  for(answer = 4; answer <= n; answer++)
  { 
    if(!prime[answer] && !prime[n - answer])
    {
      break;
    }
  }
}

void WriteData()
{
  printf("%d %d\n", answer, n - answer);
}

int main()
{
  memset(prime, 1, sizeof(prime));
  for(int i = 2; i < 1000009; i++)
  {
    if(prime[i] && i * 1LL * i < 1000009)
    {
      for(int j = i * i; j < 1000009; j += i)
      {
        prime[j] = false;
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
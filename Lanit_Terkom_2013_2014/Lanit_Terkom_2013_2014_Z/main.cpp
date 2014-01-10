#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define LOCAL

int n, k, a[19][19];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < k; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
}

int answer;

inline int min(int v1, int v2)
{
  return v1 < v2 ? v1 : v2;
}

inline int max(int v1, int v2)
{
  return v1 > v2 ? v1 : v2;
}

int times[19][19];
bool used[19];
int premutation[19];

void calc()
{
  memset(times, 0, sizeof(times));
  int currentAnswer = 0;
  for(int i = 0; i < k; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int start;
      if(j == 0)
      {
        start = i == 0 ? 0 : times[i - 1][j];
      }
      else
      {
        start = i == 0 ? times[i][j - 1] : max(times[i][j - 1], times[i - 1][j]);
      }
      times[i][j] = start + a[premutation[j]][i];
    }
  }
  answer = min(answer, times[k - 1][n - 1]);
}

void generatePermutationAndCalc(int countAdded)
{
  if(countAdded == n)
  {
    calc();
  }
  for(int i = 0; i < n; i++)
  {
    if(used[i])
    {
      continue;
    }
    premutation[countAdded] = i;
    used[i] = true;
    generatePermutationAndCalc(countAdded + 1);
    used[i] = false;
  }
}

void Solve()
{
  answer = 100000000;
  memset(used, 0, sizeof(used));
  generatePermutationAndCalc(0);
}

void WriteData()
{
  printf("%d\n", answer);
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  clock_t tm;
  #endif
  
  for(int T = 0; T < QWE; T++)
  {
    #ifdef LOCAL
      tm = clock();
    #endif
    ReadData();
    Solve();
    WriteData();
    #ifdef LOCAL
      tm = clock() - tm;
      printf("time:%.15f\n", ((float)tm)/CLOCKS_PER_SEC);
    #endif
  }
  return 0;
}
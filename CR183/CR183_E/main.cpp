#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, k;
int a[5009];

void ReadData()
{
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
}

int answer;
int diff[1000009], bad[1000009];

void Solve()
{
  memset(diff, 0, sizeof(diff));
  memset(bad, 0xFF, sizeof(bad));
  sort(a, a + n);
  for(int i = 0; i < n; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      diff[a[j] - a[i]]++;
    }
  }
  for(answer = 1; answer < a[n - 1] + 1; answer++)
  {
    int current = 0;
    for(int answerMul = answer; answerMul <= 1000000; answerMul += answer)
    {
      current += diff[answerMul];
    }
    //If number of pairs > (k * (k + 1)) / 2 we can't fix it
    if(current > (k * (k + 1)) / 2)
    {
      continue;
    }
    int cntToDel = 0;
    for(int i = 0; i < n; i++)
    {
      if(bad[a[i] % answer] == answer)//if there is already some x % answer == y, then we should delete one of it
      {
        cntToDel++;
      }
      else
      {
        bad[a[i] % answer] = answer;
      }
    }
    if(cntToDel <= k)
    {
      break;
    }
  }
}

void WriteData()
{
  printf("%d\n", answer);
}

/*
3
5 4
1 2 3 4 5
7 0
0 2 3 6 7 12 18
7 1
0 2 3 6 7 12 18
*/

int main()
{
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
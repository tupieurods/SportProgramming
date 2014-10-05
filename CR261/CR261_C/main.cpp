#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k, d;

void ReadData()
{
  scanf("%d %d %d", &n, &k, &d);
}

bool answer;
int numbers[1009][1009];

void Solve()
{
  answer = false;
  __int64 tst = 1LL;
  for(int i = 0; i < d; i++)
  {
    if(n <= tst)
    {
      break;
    }
    tst *= k;
  }
  if(n > tst)
  {
    return;
  }
  answer = true;
  memset(numbers, 0, sizeof(numbers));
  for(int i = 1; i < n; i++)
  {
    int over = 1;
    for(int idx = 0; idx < d; idx++)
    {
      numbers[i][idx] += numbers[i - 1][idx] + over;
      over = numbers[i][idx] / k;
      numbers[i][idx] %= k;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    for(int i = 0; i < d; i++)
    {
      for(int j = 0; j < n; j++)
      {
        printf("%d ", numbers[j][i] + 1);
      }
      printf("\n");
    }
    printf("\n");
  }
  else
  {
    printf("-1\n");
  }
}

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
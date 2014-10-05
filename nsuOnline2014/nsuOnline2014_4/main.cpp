#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, k, s;

void ReadData()
{
  scanf("%d %d %d", &n, &k, &s);
}

int answer[4];

void Solve()
{
  for(answer[0] = 1; answer[0] <= k; answer[0]++)
  {
    int t = s - answer[0];
    if((((n - 1) * k) >= t) && (((n - 1) * answer[0]) <= t))
    {
      break;
    }
  }
  if(answer[0] != k)
  {
    for(answer[1] = answer[0] + 1; answer[1] <= k; answer[1]++)
    {
      int t = s - answer[1];
      if(!((((n - 1) * k) >= t) && (((n - 1) * answer[1]) <= t)))
      {
        answer[1]--;
        break;
      }
    }
  }
  else
  {
    answer[1] = k;
  }
  for(answer[3] = k; answer[3] >= 1; answer[3]--)
  {
    int t = s - answer[3];
    if((n - 1) <= t && (((n - 1) * answer[3]) >= t))
    {
      break;
    }
  }
  if(answer[3] != 1)
  {
    for(answer[2] = answer[3] - 1; answer[2] >= 1; answer[2]--)
    {
      int t = s - answer[2];
      if(!((n - 1) <= t && (((n - 1) * answer[2]) >= t)))
      {
        answer[2]++;
        break;
      }
    }
  }
  else
  {
    answer[2] = 1;
  }
}

void WriteData()
{
  printf("%d %d %d %d\n", answer[0], answer[1], answer[2], answer[3]);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ReadData();
  Solve();
  WriteData();
  return 0;
}
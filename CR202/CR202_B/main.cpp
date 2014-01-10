#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct data
{
  int count;
  int a[9];
};

data createData()
{
  data result;
  result.count = 0;
  memset(result.a, 0, sizeof(result.a));
  return result;
}

int v;
int a[9];
data dp[1000009];
bool dpFlag[1000009];

void ReadData()
{
  scanf("%d", &v);
  for(int i = 0; i < 9; i++)
  {
    scanf("%d", &a[i]);
  }
}

const int compare(const data &v1, const data &v2)
{
  if(v1.count > v2.count)
  {
    return 1;
  }
  else if(v2.count > v1.count)
  {
    return -1;
  }
  for(int i = 8; i >= 0; i--)
  {
    if(v1.a[i] == v2.a[i])
    {
      continue;
    }
    if(v1.a[i] > v2.a[i])
    {
      return 1;
    }
    return -1;
  }
  return 0;
}

data answer;

data f(int currentV)
{
  if(dpFlag[currentV])
  {
    return dp[currentV];
  }
  data result = createData();
  for(int i = 0; i < 9; i++)
  {
    if(a[i] > currentV)
    {
      continue;
    }
    data current = f(currentV - a[i]);
    current.a[i]++;
    current.count++;
    if(compare(current, result) > 0)
    {
      result = current;
    }
  }
  dpFlag[currentV] = true;
  dp[currentV] = result;
  return result;
}

void Solve()
{
  memset(dpFlag, 0, sizeof(dpFlag));
  answer = f(v);
}

void WriteData()
{
  if(answer.count == false)
  {
    printf("-1\n");
    return;
  }
  #ifndef ONLINE_JUDGE
  printf("answerCnt: %d\n", answer.count);
  #endif
  for(int i = 8; i >= 0; i--)
  {
    for(int j = 0; j < answer.a[i]; j++)
    {
      printf("%d", i + 1);
    }
  }
  printf("\n");
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
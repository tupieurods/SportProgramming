#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
int a[100009];
char str[100009];
int sums[100009];

void ReadData()
{
  scanf("%d%*c", &n);
  memset(sums, 0, sizeof(sums));
  for(int i = 0; i < n; i++)
  {
    scanf("%d%*c", &a[i]);
    sums[i + 1] = sums[i] + a[i];
  }
  scanf("%s%*c", str);
}

int answer;

int getSum(int l, int r)
{
  return sums[r] - sums[l - 1];
}

void Solve()
{
  answer = 0;
  int i = 0;
  int sum = 0;
  while(i < n && str[i] == '0')
  {
    i++;
  }
  int sumr = 0;
  for(int j = i; j < n; j++)
  {
    if(str[j] == '1')
    {
      sumr += a[j];
    }
  }
  for(; i < n; i++)
  {
    if(str[i] == '0')
    {
      continue;
    }
    answer = max(answer, getSum(1, i) + sumr - a[i]);
    sum += a[i];
    sumr -= a[i];
  }
  answer = max(answer, sum);
}

void WriteData()
{
  printf("%d\n", answer);
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
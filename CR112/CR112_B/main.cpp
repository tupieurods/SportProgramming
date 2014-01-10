#include <stdio.h>
#include <stdlib.h>

int n, k;

void ReadData()
{
  scanf("%d %d", &n, &k);
}

__int64 check(int val)
{
  __int64 result = val;
  __int64 kf = k;
  while(true)
  {
    __int64 toAdd = val / kf;
    if(toAdd == 0)
    {
      break;
    }
    result += toAdd;
    kf *= k;
  }
  return result;
}

int answer;

void Solve()
{
  int l = 1, r = n;
  while(l < r)
  {
    int middle = l + (r - l) / 2;
    if(check(middle) >= n)
    {
      r = middle;
    }
    else
    {
      l = middle + 1;
    }
  }
  answer = l;
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
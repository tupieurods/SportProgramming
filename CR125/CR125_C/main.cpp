#include <stdio.h>

int k, b, n, t;

void ReadData()
{
  scanf("%d %d %d %d", &k, &b, &n, &t);
}

int answer;

void Solve()
{
  __int64 left = t * 1LL * (k - 1) + b;
  __int64 right = k - 1 + b;
  if(k == 1)
  {
    answer = 0;
    right = 0;
    for(int i = 0; i < n; i++)
    {
      right = right + b;
    }
    left = t;
    for(int i = 0; i <= n; i++)
    {
      if(left > right)
      {
        break;
      }
      else
      {
        answer++;
        left += b;
      }
    }
    return;
  }
  answer = n;
  for(int i = n; i >= 0; i--)
  {
    if(left < right)
    {
      break;
    }
    else
    {
      answer--;
      right *= k;
    }
  }
  answer++;
}

void Solve2()
{
  __int64 a0 = 1;
  __int64 a1 = a0 * k + b;
  int step = 0;
  while(!(t >= a0 && t < a1))
  {
    step++;
    a0 = a1;
    a1 = a1 * k + b;
  }
  answer = n - step;
}

void WriteData()
{
  if(answer < 0)
    answer = 0;
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
    //Solve();
    Solve2();
    WriteData();
  }
  return 0;
}
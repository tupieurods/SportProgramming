#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int a, b, s;

void ReadData()
{
  scanf("%d %d %d", &a, &b, &s);
}

bool answer;

void Solve()
{
  answer = false;
  if(a < b)
  {
    std::swap(a, b);
  }
  for(int i = 1; i * 1LL * i <= s; i++)
  {
    if(i > a)
    {
      break;
    }
    int c1 = s % i;
    int c2 = s / i;
    if(s % i == 0 && (s / i <= b || (b >= i && s / i <= a)))
    {
      answer = true;
      return;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
}

//#define LOCAL

int main()
{
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
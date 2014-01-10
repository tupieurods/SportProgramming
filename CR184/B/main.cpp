#include <stdio.h>
#include <algorithm>
//#include <vector>

//using namespace std;

//vector<int>

__int64 p, q;
int n;
__int64 numbers[90];
bool answer;

void ReadData()
{
  scanf("%I64d %I64d", &p, &q);
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%I64d", &numbers[n - 1 - i]);
  }
}

__int64 gcd(__int64 a, __int64 b)
{
  if(b == 0LL)
    return a;
  return gcd(b, a % b);
}

void Solve()
{
  answer = true;
  __int64 t = gcd(p, q);
  p /= t;
  q /= t;
  if(n == 1)
  {
    answer = q == 1 && numbers[0] == p;
    return;
  }
  __int64 top = 1, down = numbers[0];
  for(int i = 1; i < n; i++)
  {
    top = top + down * numbers[i];
    __int64 t = gcd(top, down);
    top /= t;
    down /= t;
    std::swap(top, down);
  }
  std::swap(top, down);
  answer = q == down && top == p;
  //printf("%I64d/%I64d\n", top, down);
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

int main()
{
  int QWE;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #else
  QWE = 1;
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
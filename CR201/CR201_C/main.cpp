#include <stdio.h>
#include <algorithm>

using namespace std;

int n, maximal;
int a[109];

void ReadData()
{
  scanf("%d", &n);
  maximal = -1;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
    maximal = max(maximal, a[i]);
  }
}

int gcd(int v1, int v2)
{
  if(v2 == 0)
  {
    return v1;
  }
  return gcd(v2, v1 % v2);
}

bool answer;

void Solve()
{
  int b = gcd(a[0], a[1]);
  for(int i = 2; i < n; i++)
  {
    b = gcd(b, a[i]);
  }
  answer = (maximal / b - n) % 2 == 1;
}

void WriteData()
{
  if(answer)
  {
    printf("Alice\n");
  }
  else
  {
    printf("Bob\n");
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
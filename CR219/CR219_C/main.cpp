#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <algorithm>

using namespace std;

int s[500009];
int n;

void ReadData()
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &s[i]);
  }
}

int answer;

void Solve()
{
  answer = n;
  int pared = 0;
  sort(s, s + n);
  int i = 0, j = n / 2, center = n/ 2;;
  while(i < center && j < n)
  {
    if(s[i] * 2 <= s[j])
    {
      pared++;
      i++;
      j++;
    }
    else
    {
      j++;
    }
  }
  answer -= pared;
}

void WriteData()
{
  printf("%d\n", answer);
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
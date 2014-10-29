#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int a, b, c;

void ReadData()
{
  scanf("%d%d%d", &a, &b, &c);
}

int answer;

void Solve()
{
  answer = a + b + c;
  answer = max(answer, a * b + c);
  answer = max(answer, a * b * c);
  answer = max(answer, a + b * c);
  answer = max(answer, (a + b) * c);
  answer = max(answer, a * (b + c));
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
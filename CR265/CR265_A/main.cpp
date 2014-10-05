#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
char str[109];

void ReadData()
{
  scanf("%d%*c", &n);
  scanf("%s%*c", str);
}

int answer;

void Solve()
{
  answer = 0;
  for(int i = 0; i < n; i++)
  {
    if(str[i] == '1')
    {
      answer++;
      continue;
    }
    break;
  }
  answer = std::min(n, answer + 1);
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
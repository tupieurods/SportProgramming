#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[100009];

void ReadData()
{
  scanf("%s", str);
}

int answer;

void Solve()
{
  answer = 0;
  int len = strlen(str);
  int tmp = 0;
  for(int i = 0; i < len; i++)
  {
    tmp = (tmp * 10 + (int)(str[i] - '0')) % 4;
  }
  if(tmp == 0)
  {
    answer = 4;
  }
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[1009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

int answer;

void Solve()
{
  answer = 1;
  for(int i = 0; i < len; i++)
  {
    int cnt = 1;
    int last = 0;
    for(int j = i + 1; j < len; j++)
    {
      if(str[j] == str[i] && last % 2 == 0)
      {
        last = 0;
        cnt++;
        continue;
      }
      last++;
    }
    answer = max(answer, cnt);
  }
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
  scanf("%d%*c", &QWE);
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
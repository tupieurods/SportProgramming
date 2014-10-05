#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n;
bool d[109];

void ReadData()
{
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
}

int answer;

void Solve()
{
  answer = 0;
  for(int T = 0; T < 2; T++)
  {
    int cnt = 0;
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++)
    {
      int val;
      scanf("%d", &val);
      if(d[val] == false)
      {
        d[val] = true;
        answer++;
      }
    }
  }
}

void WriteData()
{
  printf("%s\n", answer == n ? "I become the guy." : "Oh, my keyboard!");
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
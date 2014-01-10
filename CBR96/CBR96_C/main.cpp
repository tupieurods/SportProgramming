#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <deque>

int n;
char str[119];

void ReadData()
{
  gets(str);
  //fgets(str, 110, stdin);
  n = strlen(str);
}

int reverse(int value)
{
  int result = 0;
  int cnt = 0;
  while(value != 0)
  {
    cnt++;
    result |= (value & 1);
    value >>= 1;
    result <<= 1;
  }
  while(cnt < 7)
  {
    cnt++;
    result <<= 1;
  }
  return result;
}

std::deque<int> answer;

void Solve()
{
  int prev = 0;
  for(int i = n - 1; i >= 0; i--)
  {
    int current = reverse((int)str[i]);
    int prevCurrent = i == 0 ? 0 : reverse((int)(str[i - 1]));
    int toAdd = prevCurrent - current;
    if(toAdd < 0)
    {
      toAdd += 256;
    }
    if(toAdd >= 256)
    {
      toAdd %= 256;
    }
    answer.push_front(toAdd);
  }
}

void WriteData()
{
  for(int i = 0; i < answer.size(); i++)
  {
    printf("%d\n", answer[i]);
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, m, cnt;
int toAns[2000009];
bool answer;

void ReadData()
{
  scanf("%d %d", &n, &m);
}

void Solve()
{
  answer = false;
  memset(toAns, 0xFF, sizeof(toAns));
  toAns[0] = -1;
  cnt = 0;
  while(n != 0 && m != 0)
  {
    cnt++;
    toAns[cnt] = 1;
    m--;
    cnt++;
    toAns[cnt] = 0;
    n--;
  }
  if(n == 1)
  {
    toAns[0] = 0;
    n = 0;
  }
  if(m != 0)
  {
    cnt++;
    toAns[cnt] = 1;
    m--;
  }
  for(int i = 1; i <= cnt && m != 0; i += 2)
  {
    toAns[i]++;
    m--;
  }
  answer = ((n == 0) && (m == 0));
}

void WriteData()
{
  if(answer == false)
  {
    printf("-1\n");
    return;
  }
  for(int i = 0; i < 2000009; i++)
  {
    if(toAns[i] == 0)
    {
      printf("0");
    }
    else if(toAns[i] == 1)
    {
      printf("1");
    }
    else if(toAns[i] == 2)
    {
      printf("11");
    }
  }
  printf("\n");
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
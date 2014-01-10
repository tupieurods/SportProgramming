#include <stdio.h>
#include <stdlib.h>

int n;
char c;
char states[3][15] = 
{
  "aisle",
  "window",
  "neither"
};

void ReadData()
{
  scanf("%d%c%*c", &n, &c);
}

int answer;

void Solve()
{
  answer = 2;
  if(n < 3)
  {
    if(c == 'A' || c == 'D')
      answer = 1;
    else
      answer = 0;
  }
  else if(n < 21)
  {
    if(c == 'A' || c == 'F')
      answer = 1;
    else
      answer = 0;
  }
  else
  {
    if(c == 'A' || c == 'K')
      answer = 1;
    else if(c == 'C' || c == 'D' || c == 'G' || c == 'H')
      answer = 0;
  }
}

void WriteData()
{
  printf("%s\n", states[answer]);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int hs, ms, ht, mt;

void ReadData()
{
  scanf("%d:%d", &hs, &ms);
  scanf("%d:%d", &ht, &mt);
}

int answerH, answerM;

void Solve()
{
  answerH = hs - ht;
  answerM = ms - mt;
  if(answerM < 0)
  {
    answerH--;
    answerM = 60 + answerM;
  }
  if(answerH < 0)
  {
    answerH = 24 + answerH;
  }
}

void WriteData()
{
  printf("%02d:%02d\n", answerH, answerM);
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
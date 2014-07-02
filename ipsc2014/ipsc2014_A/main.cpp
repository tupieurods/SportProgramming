#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char p[100], q[100];

void ReadData()
{
  scanf("%s%*c", p);
  scanf("%s%*c", q);
  /*printf("%s\n", p);
  printf("%s\n", q);*/
}

char answer[2][100];
int answerIdx;

void Solve()
{
  int l1 = strlen(p), l2 = strlen(q);
  answerIdx = 0;
  memset(answer, 0, sizeof(answer));
  answer[0][0] = '*';
  for(int i = 0; i < l1; i++)
  {
    answer[0][i + 1] = p[i];
  }
  answer[0][l1 + 1] = '*';
  int idx = 0;
  int l = std::min(l1, l2);
  for(int i = 0; i < l; i++)
  {
    if(p[i] != q[i])
    {
      int cnt = l2 - i;
      for(int j = 0; j < cnt; j++)
      {
        answer[1][idx] = '<';
        idx++;
      }
      for(int j = i; j < l1; j++)
      {
        answer[1][idx] = p[j];
        idx++;
      }
      answer[1][idx] = '*';
      return;
    }
  }
  if(l1 > l2)
  {
    for(int j = l2; j < l1; j++)
    {
      answer[1][idx] = p[j];
      idx++;
    }
    answer[1][idx] = '*';
  }
  else
  {
    for(int j = l1; j < l2; j++)
    {
      answer[1][idx] = '<';
      idx++;
    }
    answer[1][idx] = '*';
  }
  answer[1][idx] = '*';
}

void WriteData()
{
  printf("%s\n", answer[strlen(answer[0]) < strlen(answer[1]) ? 0 : 1]);
}

int main()
{
  int QWE = 1;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%*c", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
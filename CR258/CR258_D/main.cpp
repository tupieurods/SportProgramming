#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

__int64 answer[2], ch[2][2];

void Solve()
{
  memset(answer, 0, sizeof(answer));
  memset(ch, 0, sizeof(ch));
  for(int i = 0; i < len; i++)
  {
    int idx = str[i] - 'a';
    ch[idx][i % 2]++;
    if(i % 2 == 0)
    {
      answer[0] += ch[idx][1];
      answer[1] += ch[idx][0];
    }
    else
    {
      answer[0] += ch[idx][0];
      answer[1] += ch[idx][1];
    }
    
  }
}

void WriteData()
{
  printf("%I64d %I64d\n", answer[0], answer[1]);
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[50], str2[50];
int l1, l2, cnt;

void ReadData()
{
  scanf("%s%*c", str1);
  l1 = strlen(str1);
  scanf("%s%*c", str2);
  l2 = strlen(str2);
}

int l, r;
bool answer;

void Solve()
{
  answer = true;
  int pos = 0;
  while(str1[pos] != '|')
  {
    pos++;
  }
  l = pos;
  r = l1 - 1 - pos;
  cnt = l1 + l2 - 1;
  if(cnt % 2 == 1)
  {
    answer = false;
  }
  cnt /= 2;
  if(r > cnt || l > cnt)
  {
    answer = false;
  }
}

void WriteData()
{
  if(answer)
  {
    int pos = 0;
    while(l != cnt)
    {
      printf("%c", str2[pos]);
      pos++;
      l++;
    }
    printf("%s", str1);
    while(r != cnt)
    {
      printf("%c", str2[pos]);
      pos++;
      r++;
    }
    printf("\n");
  }
  else
  {
    printf("Impossible\n");
  }
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
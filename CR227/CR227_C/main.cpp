#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[100009];
int len;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
}

int answer;

void Solve()
{
  if(len == 1)
  {
    answer = 1;
    return;
  }
  int cnt = 1;
  int ind = -1;
  int i = 1;
  while(i < len && str[i] == '0')
  {
    i++;
  }
  for(; i < len; i++)
  {
    cnt++;
    int len1 = i;
    int len2 = 1;
    if(i < len - 1 && str[i + 1] == '0')
    {
      i++;
      while(i < len && str[i] == '0')
      {
        i++;
        len2++;
      }
      i--;
    }
    if(len1 == len2)
    {
      for(int j = 0; j < len1; j++)
      {
        if((int)(str[j] - '0') < (int)(str[j + len1] - '0'))
        {
          ind = cnt;
          break;
        }
      }
    }
    else if(len1 < len2)
    {
      ind = cnt;
    }
  }
  answer = ind == -1 ? cnt : cnt - ind + 1;
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
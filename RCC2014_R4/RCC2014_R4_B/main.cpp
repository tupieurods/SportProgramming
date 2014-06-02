#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

//#define LOCAL

int k, len, cnt;
char str[100009];
int deactive[100009];

void ReadData()
{
  scanf("%d", &k);
  scanf("%s%*c", str);
}

bool answer;
int p[2];

void Solve()
{
  answer = true;
  len = strlen(str);
  int last = 0;
  int bk = k;
  for(int i = len - 1; i >= 0 && k > 0; i--)
  {
    if(str[i] != '0')
    {
      k--;
      deactive[i] = cnt;
    }
    else if(str[i] == '0')
    {
      if(last != 2)
      {
        if(last == 0)
        {
          last = 1;
          p[0] = i;
        }
        else
        {
          last = 2;
          p[1] = i;
        }
      }
      else
      {
        k--;
        deactive[i] = cnt;
      }
    }
  }
  /*if(k != 0)
  {
    answer = false;
  }*/
  int f = -1;
  int l1 = -1, l2 = -1;
  int checker = 0;
  for(int i = 0; i < len; i++)
  {
    if(deactive[i] != cnt)
    {
      if(f == -1)
      {
        f = str[i] - '0';
      }
      l2 = l1;
      l1 = str[i] - '0';
      checker++;
    }
  }
  if((checker != len - bk) || (l1 != 0 || l2 != 0) || f <= 0)
  {
    if(len - bk == 1 && last == 1)
    {
      //deactive[p[0]] = cnt;
      return;
    }
    else if(len - bk == 1 && last == 2)
    {
      deactive[p[0]] = cnt;
      return;
    }
    answer = false;
  }
}

void WriteData()
{
  if(answer)
  {
    for(int i = 0; i < len; i++)
    {
      if(deactive[i] != cnt)
      {
        printf("%c", str[i]);
      }
    }
    printf("\n");
  }
  else
  {
    printf("-1\n");
  }
}

int main()
{
  memset(deactive, 0, sizeof(deactive));
  cnt = 0;
  int QWE = 1;
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    cnt++;
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
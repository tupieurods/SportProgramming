#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

//#define LOCAL

char str[100009];
bool s[100009];
int len;

void ReadData()
{
  gets(str);
  len = strlen(str);
}

void Solve()
{
  memset(s, 0, sizeof(s));
  int i = 0;
  while(i < len)
  {
    if(str[i] == '(')
    {
      bool flag = false;
      int cnt = 0;
      int j = i + 1;
      while(j < len)
      {
        if(str[j] == ')')
        {
          flag = true;
          break;
        }
        else if((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
        {
          cnt++;
          j++;
        }
        else
        {
          break;
        }
      }
      if(flag == false || cnt == 0)
      {
        i++;
      }
      else
      {
        s[i] = true;
        s[j] = true;
        i = j + 1;
      }
    }
    else
    {
      bool flag = true;
      if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
        || str[i] == ' ' || str[i] == ')'
        || (str[i] >= '0' && str[i] <= '9')))
      {
        if(i + 1 < len && str[i + 1] == ')')
        {
          s[i] = true;
          s[i + 1] = true;
          i += 2;
        }
        else
        {
          i++;
        }
      }
      else
      {
        i++;
      }
    }
  }
}

void WriteData()
{
  bool c = false;
  for(int i = 0; i < len; i++)
  {
    if(s[i])
    {
      if(c)
      {
        printf("%c</S>", str[i]);
      }
      else
      {
        printf("<S>%c", str[i]);
      }
      c = !c;
    }
    else
    {
      printf("%c", str[i]);
    }
  }
  printf("\n");
}

int main()
{
  int QWE = 1;
  #ifdef LOCAL
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
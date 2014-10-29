#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str1[19], str2[19];
int l;
int balance;

void ReadData()
{
  scanf("%s%*c", str1);
  scanf("%s%*c", str2);
  l = strlen(str1);
  balance = 0;
  for(int i = 0; i < l; i++)
  {
    if(str1[i] == '+')
    {
      balance++;
    }
    else
    {
      balance--;
    }
  }
}

double answer1, answer2;
char str[19];

void check(int idx)
{
  if(idx == l)
  {
    answer2 += 1.0;
    int b = 0;
    for(int i = 0; i < l; i++)
    {
      if(str[i] == '+')
      {
        b++;
      }
      else
      {
        b--;
      }
    }
    if(b == balance)
    {
      answer1 += 1.0;
    }
    return;
  }
  if(str2[idx] != '?')
  {
    str[idx] = str2[idx];
    check(idx + 1);
  }
  else
  {
    str[idx] = '+';
    check(idx + 1);
    str[idx] = '-';
    check(idx + 1);
  }
}

void Solve()
{
  answer1 = answer2 = 0;
  check(0);
}

void WriteData()
{
  printf("%.15lf\n", answer1 / answer2);
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
}
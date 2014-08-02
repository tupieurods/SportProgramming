#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char s[109], t[109];
int ls, lt;

void ReadData()
{
  scanf("%s%*c", s);
  scanf("%s%*c", t);
  ls = strlen(s);
  lt = strlen(t);
}

int answer;

int cs[30], ct[30];

void Solve()
{
  if(lt > ls)//не можем нарастить строку s
  {
    answer = 3;
    return;
  }
  memset(ct, 0, sizeof(ct));
  memset(cs, 0, sizeof(cs));
  for(int i = 0; i < ls; i++)
  {
    cs[s[i] - 'a']++;
  }
  for(int i = 0; i < lt; i++)
  {
    ct[t[i] - 'a']++;
  }
  if(lt == ls)
  {
    for(int i = 0; i < 26; i++)
    {
      if(cs[i] != ct[i])//not enough letters
      {
        answer = 3;
        return;
      }
    }
    answer = 1;//swap only
    return;
  }
  //ls > lt
  /*bool arr = false;
  bool aut = false;*/
  if(strstr(s, t) != NULL)
  {
    answer = 0;
    return;
  }
  int idxT = 0;
  for(int i = 0; i < ls; i++)
  {
    if(s[i] == t[idxT])
    {
      idxT++;
    }
    if(idxT == lt)
    {
      answer = 0;
      return;
    }
  }
  answer = 2;
  for(int i = 0; i < 26; i++)
  {
    if(cs[i] < ct[i])//not enough letters
    {
      answer = 3;
      return;
    }
  }
}

void WriteData()
{
  if(answer == 0)
  {
    printf("automaton\n");
  }
  else if(answer == 1)
  {
    printf("array\n");
  }
  else if(answer == 2)
  {
    printf("both\n");
  }
  else
  {
    printf("need tree\n");
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
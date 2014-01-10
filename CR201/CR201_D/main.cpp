#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[109], s2[109], virus[109];
int s1l, s2l, virusl;

void ReadData()
{
  scanf("%s%*c", s1);
  scanf("%s%*c", s2);
  scanf("%s%*c", virus);
  s1l = strlen(s1);
  s2l = strlen(s2);
  virusl = strlen(virus);
}

bool answer;
char answerStr[109];
int dp[109][109][109];
int step[109][109][109];
const int inf = 2000000000;

int f(int s1pos, int s2pos, int viruspos)
{
  //printf("%d %d %d\n", s1pos, s2pos, viruspos);
  if(viruspos == -1) throw;
  if(s1pos == -1 || s2pos == -1)
  {
    return 0;
  }
  if(dp[s1pos][s2pos][viruspos] != -1)
  {
    return dp[s1pos][s2pos][viruspos];
  }
  int result = 0, stp = 0;
  if(s1[s1pos] == s2[s2pos])//Есть возможность взять символ
  {
    if(virus[viruspos] == s1[s1pos])//Символ есть в текущей позиции вируса
    {
      //Не брать символ
      int r1 = f(s1pos - 1, s2pos, viruspos);
      int r2 = f(s1pos, s2pos - 1, viruspos);
      if(r1 > r2)
      {
        result = r1;
        stp = 0;
      }
      else
      {
        result = r2;
        stp = 1;
      }
      //Попробовать взять символ
      if(viruspos != 0)
      {
        int r3 = f(s1pos - 1, s2pos - 1, viruspos - 1) + 1;
        if(r3 > result)
        {
          result = r3;
          stp = 2;
        }
      }
    }
    else//Символа нет в текущей позиции вируса
    {
      //Не брать символ
      /*int r1 = f(s1pos - 1, s2pos, virusl - 1);
      int r2 = f(s1pos, s2pos - 1, virusl - 1);
      if(r1 > r2)
      {
        result = r1;
        stp = 3;
      }
      else
      {
        result = r2;
        stp = 4;
      }*/
      //Попробовать взять символ
      /*int newVirPos = virus[virusl - 1] == s1[s1pos] 
            ? virusl - 2 : virusl - 1;*/
      int newVirPos = virusl - 1;
      while(newVirPos != 0 && virus[newVirPos] == s1[s1pos])
      {
        newVirPos--;
      }
      int r3 = f(s1pos - 1, s2pos - 1, newVirPos) + 1;
      if(r3 > result)
      {
        result = r3;
        stp = 5;
      }
    }
  }
  else//Взять символ в любом случае не получится
  {
    int r1 = f(s1pos - 1, s2pos, viruspos);
    int r2 = f(s1pos, s2pos - 1, viruspos);
    if(r1 > r2)
    {
      result = r1;
      stp = 0;
    }
    else
    {
      result = r2;
      stp = 1;
    }
  }
  dp[s1pos][s2pos][viruspos] = result;
  step[s1pos][s2pos][viruspos] = stp;
  return result;
}

void g(int s1pos, int s2pos, int viruspos)
{
  if(s1pos == -1 || s2pos == -1)
  {
    return;
  }

  //printf("g(%d, %d, %d):%d\n", s1pos, s2pos, viruspos, step[s1pos][s2pos][viruspos]);
  switch(step[s1pos][s2pos][viruspos])
  {
    case 0:
    {
      g(s1pos - 1, s2pos, viruspos);
      break;
    }
    case 1:
    {
      g(s1pos, s2pos - 1, viruspos);
      break;
    }
    case 2:
    {
      g(s1pos - 1, s2pos - 1, viruspos - 1);
      printf("%c", s1[s1pos]);
      break;
    }
    case 3:
    {
      g(s1pos - 1, s2pos, virusl - 1);
      break;
    }
    case 4:
    {
      g(s1pos, s2pos - 1, virusl - 1);
      break;
    }
    case 5:
    {
      /*int newVirPos = virus[virusl - 1] == s1[s1pos] 
            ? virusl - 2 : virusl - 1;*/
      int newVirPos = virusl - 1;
      while(newVirPos != 0 && virus[newVirPos] == s1[s1pos])
      {
        newVirPos--;
      }
      g(s1pos - 1, s2pos - 1, newVirPos);
      printf("%c", s1[s1pos]);
      break;
    }
  }
}

void Solve()
{
  memset(answerStr, 0, sizeof(answerStr));
  memset(dp, 0xFF, sizeof(dp));
  memset(step, 0xFF, sizeof(step));
  answer = false;
  printf("len:%d\n", f(s1l - 1, s2l - 1, virusl - 1));
  if(f(s1l - 1, s2l - 1, virusl - 1) > 0)
  {
    answer = true;
  }
}

void WriteData()
{
  if(answer == false)
  {
    printf("0\n");
  }
  else
  {
    g(s1l - 1, s2l - 1, virusl - 1);//printf("%s\n", answerStr);
    printf("\n");
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
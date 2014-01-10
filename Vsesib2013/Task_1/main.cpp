#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct unit
{
  bool haveEngine;
  bool connectionType;
  bool connected, worked;
};

char conf[512], prog[10024];
unit units[13];
int cnt;

void ReadData()
{
  scanf("%s%*c", conf);
  scanf("%s%*c", prog);
  int len = strlen(conf);
  cnt = 0;
  for(int i = 0; i < len; i++)
  {
    i++;
    units[cnt].haveEngine = true;
    if(i < len)
    {
      units[cnt].haveEngine = conf[i] != '#';
      if(units[cnt].haveEngine)
      {
        units[cnt].connectionType = conf[i] == '|';
      }
      else if(i + 1 < len)
      {
        i++;
        units[cnt].connectionType = conf[i] == '|';
      }
    }
    units[cnt].connected = true;
    units[cnt].worked = false;
    cnt++;
  }
}

bool answer;

bool checkConnection(int stNum)
{
  while(stNum > 0)
  {
    if(units[stNum - 1].connectionType)
    {
      stNum--;
      continue;
    }
    break;
  }
  while(stNum > 0)
  {
    if(units[stNum - 1].connected)
    {
      return false;
    }
    stNum--;
  }
  return true;
}

bool tryToOnEngine(int stNum)
{
  if(!units[stNum].connected 
    || !units[stNum].haveEngine
    || units[stNum].worked)
  {
    return false;
  }
  units[stNum].worked = true;
  return true;
}

void Solve()
{
  answer = false;
  int len = strlen(prog);
  for(int i = 0; i < len; i++)
  {
    int stNum = (int)(prog[i] - '0');
    stNum--;
    if(i + 1 >= len)
    {
      return;
    }
    i++;
    if(prog[i] == '+' || prog[i] == '-')
    {
      if(!checkConnection(stNum))
      {
        return;
      }
      if(prog[i] == '+')
      {
        if(!tryToOnEngine(stNum))
        {
          return;
        }
      }
      else
      {
        if(!units[stNum].connected 
          || (units[stNum].haveEngine && !units[stNum].worked))
        {
          return;
        }
        for(int j = 0; j < stNum; j++)
        {
          if(units[j].connected)
          {
            return;
          }
        }
        units[stNum].connected = false;
      }
    }
    else
    {
      int stNum2 = (int)(prog[i] - '0');
      stNum2--;
      if(i + 1 >= len)
      {
        return;
      }
      i++;
      if(prog[i] != '+')
      {
        return;
      }
      if(!checkConnection(stNum) || !checkConnection(stNum2)
        || !tryToOnEngine(stNum) || !tryToOnEngine(stNum2))
      {
        return;
      }
    }
  }
  for(int i = 0; i < cnt - 1; i++)
  {
    if(units[i].connected == true)
    {
      return;
    }
  }
  if(units[cnt - 1].connected == false)
  {
    return;
  }
  answer = true;
}

void WriteData()
{
  if(answer)
  {
    printf("CORRECT\n");
  }
  else
  {
    printf("INCORRECT\n");
  }
}

int main()
{ 
  int QWE;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &QWE);
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
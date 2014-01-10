#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char illegal = 0;
const char xWins = 1;
const char oWins = -1;
const char draw = 2;
char field[3][3];
char cache[2 << 18];
char answer;

bool ReadData()
{
  char str[400];

  scanf("%s", &str);
  if(strcmp(str, "Qc") == 0)
    return false;

  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      switch(str[j])
      {
      case 'X': field[i][j] = 1; break;
      case '0': field[i][j] = -1; break;
      case '.': field[i][j] = 0; break;
      }
    }
    if (i < 2) scanf("%s", &str);
  }
  return true;
}

int getWinsCount(int player)
{
  int result = 0;
  for(int i = 0; i < 3; i++)
  {
    int vert = 0, horiz = 0;
    for(int j = 0; j < 3; j++)
    {
      vert += field[i][j];
      horiz += field[j][i];
    }
    if(vert == player * 3)
      result++;
    if(horiz == player * 3)
      result++;
  }
  if(field[0][0] + field[1][1] + field[2][2] == player * 3)
    result++;
  if(field[0][2] + field[1][1] + field[2][0] == player * 3)
    result++;
  return result;
}

int getHashCode()
{
  int number = 0, result = 0;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(field[i][j] == 1)
      {
        result |= 1 << (number * 2);
      }
      else if(field[i][j] == -1)
      {
        result |= 1 << (number * 2 + 1);
      }
      number++;
    }
  }
  return result;
}

void Solve()
{
  int currentState = getHashCode();
  answer = cache[currentState];
}

void WriteData()
{
  switch(answer)
  {
  case xWins:
    printf("X wins.\n");
    break;
  case oWins:
    printf("0 wins.\n");
    break;
  case draw:
    printf("Game is a draw.\n");
    break;
  case illegal:
    printf("Illegal position.\n");
    break;
  }
}

void show()
{
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      if(field[i][j] == 1)
      {
        printf("X");
      }
      else if(field[i][j] == -1)
      {
        printf("0");
      }
      else
      {
        printf(".");
      }
    }
    printf("\n");
  }
}

int f(int player, int setted)
{
  int hashCode = getHashCode();
  if(cache[hashCode] != illegal)
    return cache[hashCode];

  int result = illegal;
  if(getWinsCount(player) != 0)
    result = player;
  else if(getWinsCount(-player) != 0)
    result = -player;
  else if (setted == 9)
    result = draw;
  else
  {
    bool canWin = false;
    bool canDraw = false;

    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(field[i][j] != 0)
          continue;

        field[i][j] = player;

        int tmpResult = f(-player, setted + 1);
        if (tmpResult == player) canWin = true;
        else if (tmpResult == draw) canDraw = true;

        field[i][j] = 0;
      }
    }

    if (canWin) result = player;
    else if (canDraw) result = draw;
    else result = -player;
  }

  cache[hashCode] = result;
  return result;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  memset(cache, 0, sizeof(cache));
  memset(field, 0, sizeof(field));
  f(1, 0);
  while(ReadData())
  {
    Solve();
    WriteData();
  }
}
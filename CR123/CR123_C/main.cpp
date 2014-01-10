#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

struct block
{
  char type[29];
  char message[29];
};

int n;
int st[100009];
block blocks[51000];
std::vector<int> toCheck;
char exc[29];
int top, current;

void ReadData()
{
  for(int i = 0; i < 5100; i++)
  {
    memset(blocks[i].type, 0, sizeof(blocks[i].type));
    memset(blocks[i].message, 0, sizeof(blocks[i].message));
  }
  scanf("%d%*c", &n);
  memset(st, 0xFF, sizeof(st));
  memset(exc, 0, sizeof(exc));
  toCheck.clear();
  char str[59];
  top = -1;
  current = -1;
  for(int i = 0; i < n; i++)
  {
    fgets(str, 59, stdin);
    int len = strlen(str);
    int j = 0;
    while(j < len && str[j] == ' ')
      j++;
    //try
    if(str[j] == 't' && str[j + 1] == 'r')
    {
      current++;
      top++;
      st[top] = current;
      continue;
    }
    //throw
    if(str[j] == 't' && str[j + 1] == 'h')
    {
      while(str[j - 1] != '(') j++;
      while(str[j] == ' ') j++;
      int index = 0;
      while(str[j] != ' ' && str[j] != ')')
      {
        exc[index] = str[j];
        index++;
        j++;
      }
      for(j = top; j >= 0; j--)
      {
        toCheck.push_back(st[j]);
      }
      continue;
    }
    //catch
    if(str[j] == 'c')
    {
      while(str[j - 1] != '(') j++;
      while(str[j] == ' ') j++;
      int index = 0;
      while(str[j] != ' ' && str[j] != ',')
      {
        blocks[st[top]].type[index] = str[j];
        index++;
        j++;
      }
      while(str[j - 1] != '\"') j++;
      index = 0;
      while(str[j] != '\"')
      {
        blocks[st[top]].message[index] = str[j];
        index++;
        j++;
      }
      st[top] = -1;
      top--;
      continue;
    }
  }
}

bool answer;

void Solve()
{
  answer = true;
  for(std::vector<int>::iterator it = toCheck.begin(); it != toCheck.end(); it++)
  {
    if(strcmp(blocks[*it].type, exc) == 0)
    {
      printf("%s\n", blocks[*it].message);
      answer = false;
      break;
    }
  }
}

void WriteData()
{
  if(answer)
  {
    printf("Unhandled Exception\n");
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k;
char str[100009], pairs[15][9];

void ReadData()
{
  scanf("%s%*c", str);
  n = strlen(str);
  scanf("%d%*c", &k);
  for(int i = 0; i < k; i++)
  {
    scanf("%s%*c", pairs[i]);
  }
}

int answer;
bool excluded[100009];

void Solve()
{
  answer = 0;
  memset(excluded, 0, sizeof(excluded));
  for(int i = 0; i < k; i++)
  {
    int first = 0, second = 0, start = -1;
    for(int index = 0; index < n; index++)
    {
      if(excluded[index])
        continue;
      if(str[index] == pairs[i][0]
          || str[index] == pairs[i][1])
      {
        if(str[index] == pairs[i][0])
        {
          first++;
        }
        else
        {
          second++;
        }
        if(start == -1)
        {
          start = index;
        }
        continue;
      }
      if(start != -1)
      {
        int toDel = first < second ? 0 : 1;
        for(int j = start; j <= index; j++)
        {
          if(str[j] == pairs[i][toDel])
          {
            excluded[j] = true;
            answer++;
          }
        }
        first = 0;
        second = 0;
        start = -1;
      }
    }
    if(start != -1)
      {
        int toDel = first < second ? 0 : 1;
        for(int j = start; j < n; j++)
        {
          if(str[j] == pairs[i][toDel])
          {
            excluded[j] = true;
            answer++;
          }
        }
        first = 0;
        second = 0;
        start = -1;
      }
  }
}

void WriteData()
{
  printf("%d\n", answer);
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
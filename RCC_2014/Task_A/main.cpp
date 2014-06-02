#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  //freopen("input.txt", "r", stdin);
  int QWE;
  scanf("%d", &QWE);
  int field[19][19];
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d", &n);
    bool answer = false;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        scanf("%d", &field[i][j]);
        if(field[i][j] == 0)
        {
          answer = true;
        }
      }
    }
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(i + 1 < n)
        {
          if(field[i][j] == field[i + 1][j])
          {
            answer = true;
            break;
          }
        }
        if(j + 1 < n)
        {
          if(field[i][j] == field[i][j + 1])
          {
            answer = true;
            break;
          }
        }
      }
      if(answer)
      {
        break;
      }
    }
    if(answer)
    {
      printf("YES\n");
    }
    else
    {
      printf("NO\n");
    }
  }
  return 0;
}
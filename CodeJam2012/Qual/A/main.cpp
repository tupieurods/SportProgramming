#include <stdio.h>
#include <stdlib.h>

#define LOCAL

int a[4][4];
int status;
int xT = -1, yT = -1;

bool checkWon(int cnt)
{
  int sum1, sum2;
  if(xT != -1)
  {
    a[yT][xT] = cnt > 0 ? 1 : -1;
  }
  for(int i = 0; i < 4; i++)
  {
    sum1 = 0, sum2 = 0;
    for(int j = 0; j < 4; j++)
    {
      sum1 += a[i][j];
      sum2 += a[j][i];
    }
    if(sum1 == cnt || sum2 == cnt)
      return true;
  }
  sum1 = a[0][0] + a[1][1] + a[2][2] + a[3][3];
  sum2 = a[0][3] + a[1][2] + a[2][1] + a[3][0];
  if(sum1 == cnt || sum2 == cnt)
    return true;
  return false;
}

int main()
{
  int QWE;
#ifdef LOCAL
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
#else
  
#endif
  scanf("%d\n", &QWE);
  char str[5];
  for(int T = 0; T < QWE; T++)
  {
    xT = -1, yT = -1;
    for(int i = 0; i < 4; i++)
    {
      scanf("%s\n", &str);
      status = 3;
      //printf("%s\n", str);
      for(int j = 0; j < 4; j++)
      {
        if(str[j] == '.')
        {
          a[i][j] = 0;
          status = 4;
        }
        if(str[j] == 'X')
        {
          a[i][j] = 1;
        }
        if(str[j] == 'O')
        {
          a[i][j] = -1;
        }
        if(str[j] == 'T')
        {
          a[i][j] = 0;
          xT = j;
          yT = i;
        }
      }
    }
    if(checkWon(4))
    {
      status = 1;
    }
    if(checkWon(-4))
    {
      status = 2;
    }
    switch(status)
    {
      case 1:
      {
        printf("Case #%d: X won\n", T + 1);
        break;
      }
      case 2:
      {
        printf("Case #%d: O won\n", T + 1);
        break;
      }
      case 3:
      {
        printf("Case #%d: Draw\n", T + 1);
        break;
      }
      case 4:
      {
        printf("Case #%d: Game has not completed\n", T + 1);
        break;
      }
    }
    //scanf("%s\n", &str);
    //printf("\n");
  }
  return 0;
}
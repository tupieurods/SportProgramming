#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100009];
int sums[100009][3];
int len, m;

void ReadData()
{
  scanf("%s%*c", str);
  len = strlen(str);
  scanf("%d", &m);
}

int getSum(int id, int l, int r)
{
  return sums[r][id] - sums[l - 1][id];
}

void Solve()
{
  memset(sums, 0, sizeof(sums));
  for(int i = 0; i < len; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      sums[i + 1][j] = sums[i][j];
    }
    sums[i + 1][(int)(str[i] - 'x')]++;
  }
  int localSum[3];
  for(int i = 0; i < m; i++)
  {
    int l, r;
    scanf("%d %d%*c", &l, &r);
    int cnt = r - l + 1;
    if(cnt < 3)
    {
      printf("YES\n");
      continue;
    }
    int modRez = cnt % 3;
    int divRez = cnt / 3;
    for(int j = 0; j < 3; j++)
    {
      localSum[j] = getSum(j, l, r) - divRez;
    }
    bool answer = false;
    switch(modRez)
    {
      case 0:
      {
        //answer = localSum[0] == divRez && localSum[1] == divRez && localSum[2] == divRez;
        answer = localSum[0] == 0 && localSum[1] == 0 && localSum[2] == 0;
        break;
      }
      case 1:
      {
        /*for(int j = 0; j < 3; j++)
        {
          if(localSum[j] < divRez)
          {
            break;
          }
          localSum[j] -= divRez;
        }*/
        answer = localSum[0] == 0 && localSum[1] == 1 && localSum[2] == 0
          || localSum[0] == 1 && localSum[1] == 0 && localSum[2] == 0
          || localSum[0] == 0 && localSum[1] == 0 && localSum[2] == 1;
        break;
      }
      case 2:
      {
        /*for(int j = 0; j < 3; j++)
        {
          if(localSum[j] < divRez)
          {
            break;
          }
          localSum[j] -= divRez;
        }*/
        answer = localSum[0] == 0 && localSum[1] == 1 && localSum[2] == 1
          || localSum[0] == 1 && localSum[1] == 0 && localSum[2] == 1
          || localSum[0] == 1 && localSum[1] == 1 && localSum[2] == 0;
        break;
        break;
      }
      default:
      {
        throw;
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
}

void WriteData()
{
  printf("\n");
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
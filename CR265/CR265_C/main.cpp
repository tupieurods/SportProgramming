#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int n, p;
char str[1009];

void ReadData()
{
  scanf("%d %d%*c", &n, &p);
  scanf("%s%*c", str);
}

bool answer;

void Solve()
{
  answer = false;
  char last = 'a' + p - 1;
  for(int i = n - 1; i >= 0; i--)
  {
    for(int k = 1; k < p; k++)
    {
      if(str[i] + k <= last)
      {
        if((i - 1 < 0 || (i - 1 >= 0 && str[i] + k != str[i - 1]))
          && (i - 2 < 0 || (i - 2 >= 0 && str[i] + k != str[i - 2])))
        {
          str[i] += k;
          int idx = i + 1;
          for(; idx < n; idx++)
          {
            bool flag = true;
            for(int j = 0; j < p; j++)
            {
              if((str[idx - 1] != 'a' + j)
                && ((idx - 2 < 0) ||(idx - 2 >= 0 && str[idx - 2] != 'a' + j)))
              {
                str[idx] = 'a' + j;
                flag = false;
                break;
              }
            }
            if(flag)
            {
              return;
            }
          }
          answer = true;
          return;
        }
      }
    }
  }
}

void WriteData()
{
  if(answer == false)
  {
    printf("NO\n");
  }
  else
  {
    printf("%s\n", str);
  }
}

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    ReadData();
    Solve();
    WriteData();
  }
  return 0;
}
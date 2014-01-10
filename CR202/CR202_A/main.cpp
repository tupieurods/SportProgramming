#include <stdio.h>
#include <stdlib.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d", &QWE);
  #endif
  for(int T = 0; T < QWE; T++)
  {
    int a = 0, b = 0;
    int n;
    scanf("%d", &n);
    bool answer = true;
    for(int i = 0; i < n; i++)
    {
      int current;
      scanf("%d", &current);
      if(!answer)
      {
        continue;
      }
      switch(current)
      {
        case 25:
        {
          a++;
          break;
        }
        case 50:
        {
          if(a != 0)
          {
            a--;
            b++;
          }
          else
          {
            answer = false;
          }
          break;
        }
        case 100:
        {
          if(a != 0 || b != 0)
          {
            if(b == 0)
            {
              if(a >= 3)
              {
                a -= 3;
              }
              else
              {
                answer = false;
              }
            }
            else
            {
              if(a > 0 && b > 0)
              {
                b--;
                a--;
              }
              else
              {
                answer = false;
              }
            }
          }
          else
          {
            answer = false;
          }
          break;
        }
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
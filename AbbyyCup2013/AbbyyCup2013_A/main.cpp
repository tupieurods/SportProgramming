#include <stdio.h>
#include <string.h>

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  #endif
  if(!true)
  {
    freopen("input.txt", "w", stdout);
    /*printf("A");
    for(int i = 0; i < 100000 - 2; i++)
    {
      printf("J");
    }
    printf("B");*/
    for(int i = 0; i < 100000; i++)
    {
      printf("?");
    }
    return 0;
  }
  //ReadData
  char str[100005];
  scanf("%s", &str);
  //Solve
  int len = strlen(str);
  bool used[15];
  memset(used, 0, sizeof(used));
  __int64 answer = 1LL;
  __int64 cnt = 10;
  int zero = 0;
  for(int i = 0; i < len; i++)
  {
    if(str[i] == '?')
    {
      if(i == 0)
      {
        answer *= 9;
      }
      else
      {
        zero++;
      }
    }
    else if(str[i] >= 'A' && str[i] <= 'Z')
    {
      if(!used[(int)(str[i] - 'A')])
      {
        used[(int)(str[i] - 'A')] = true;
        answer *= i == 0 ? cnt - 1LL : cnt;
        cnt--;
        //if(cnt == -1LL) throw;
      }
    }
  }
  //WriteData
  printf("%I64d", answer);
  for(int i = 0; i < zero; i++)
  {
    printf("0");
  }
  printf("\n");
  return 0;
}
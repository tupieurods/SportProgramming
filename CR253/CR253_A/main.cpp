#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int QWE = 1;
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  scanf("%d%*c", &QWE);
  #endif
  char str[1009];
  bool a[30];
  for(int T = 0; T < QWE; T++)
  {
    memset(a, 0, sizeof(a));
    gets(str);
    int answer = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
      if(str[i] >= 'a' && str[i] <= 'z')
      {
        int idx = str[i] - 'a';
        if(!a[idx])
        {
          answer++;
        }
        a[idx] = true;
      }
    }
    printf("%d\n", answer);
  }
  return 0;
}
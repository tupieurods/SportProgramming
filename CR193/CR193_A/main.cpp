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
  for(int T = 0; T < QWE; T++)
  {
    int n;
    scanf("%d%*c", &n);
    char str[2009];
    scanf("%s", str);
    int k = strlen(str);
    int answer = 0;
    int step = 0;
    char j1 = 'a', j2 = 'a', j3 = 'a';
    int current = 0;
    for(int i = 0; i < k; i++)
    {
      step++;
      if(step >= 4 && current == 0)
      {
        if(j1 == j2 && j2 == j3)
          answer++;
      }
      j1 = j2;
      j2 = j3;
      j3 = str[i];
      current++;
      current %= n;
    }
    printf("%d\n", answer);
  }
  return 0;
}
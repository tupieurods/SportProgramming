#include <stdio.h>
#include <string.h>

int main()
{
  //freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  int a[105];
  int b[105];
  for(int i = 0; i < n; i++)
  {
    scanf("%d %d", &a[i], &b[i]);
  }
  int answer = 0;
  for(int i = 0; i < n; i++)
  {
    bool opened = false;
    for(int j = 0; j < n; j++)
    {
      if(i != j)
      {
        if(a[i] == b[j])
        {
          opened = true;
          break;
        }
      }
    }
    if(!opened)
      answer++;
  }
  printf("%d\n", answer);
  return 0;
}

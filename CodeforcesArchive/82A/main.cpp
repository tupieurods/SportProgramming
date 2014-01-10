#include <stdio.h>
#include <stdlib.h>

int main()
{
  char names[5][15] = 
  {
    "Sheldon",
    "Leonard",
    "Penny",
    "Rajesh",
    "Howard"
  };
  int n;
  scanf("%d", &n);
  __int64 l = 1, r = 5;
  __int64 cnt = 5, cntUniq = 1;
  while(r < n)
  {
    cntUniq *= 2LL;
    cnt = 5 * cntUniq;
    l = r + 1;
    r = r + cnt;
  }
  __int64 pos = l + cntUniq;
  int index = 0;
  while(pos <= n)
  {
    pos += cntUniq;
    index++;
  }
  printf("%s\n", names[index]);
  return 0;
}
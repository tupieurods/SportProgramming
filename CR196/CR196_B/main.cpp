#include <stdio.h>
#include <stdlib.h>

int evklid(int v1, int v2)
{
  if(v2 == 0)
    return v1;
  return evklid(v2, v1 % v2);
}

int main()
{
  //ReadData
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  //Solve
  int ans1 = 100000, ans2 = 1;
  int top1 = a * d;
  int top2 = c * b;
  if(top1 < top2)
  {
    ans1 = b * c - a *d;
    ans2 = b * c;
  }
  else if(top1 > top2)
  {
    ans1 = a * d - b *c;
    ans2 = a * d;
  }
  else
  {
    ans1 = 0;
    ans2 = 1;
  }
  if(ans1 != 0)
  {
    d = evklid(ans1, ans2);
    ans1 /= d;
    ans2 /= d;
  }
  //WriteData
  printf("%d/%d\n", ans1, ans2);
  return 0;
}
#include <stdio.h>

int main()
{
  char str[9][10]=
  {
    "few",
    "several",
    "pack",
    "lots",
    "horde",
    "throng",
    "swarm",
    "zounds",
    "legion"
  };
  int bounds[9][2] = 
  {
    {1, 4},
    {5, 9},
    {10, 19},
    {20, 49},
    {50, 99},
    {100, 249},
    {250, 499},
    {500, 999},
    {1000, 3000}
  };
  int val;
  scanf("%d", &val);
  for(int i = 0; i < 10; i++)
  {
    if(val >= bounds[i][0] && val <= bounds[i][1])
    {
      val = i;
      break;
    }
  }
  printf("%s\n", str[val]);
  return 0;
}
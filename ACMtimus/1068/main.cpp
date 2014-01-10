#include <stdio.h>
#include <algorithm>

int main()
{
  int n;
  scanf("%d", &n);
  int start, finish;
  start = 1; finish = n;
  if(start > finish)
    std::swap(start, finish);
  int answer = 0;
  for(int i = start; i <= finish; i++)
  {
    answer += i;
  }
  printf("%d\n", answer);
  return 0;
}
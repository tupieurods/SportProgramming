#include <stdio.h>

int check(int value)
{
  int result = 0;
  int p = 1;
  while(value != 0)
  {
    int last = value % 10;
    if(last == 4 || last == 7)
    {
      result += last * p;
      p *= 10;
    }
    value /= 10;
  }
  return result;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);
  int answer = a + 1;
  while(check(answer) != b)
  {
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}
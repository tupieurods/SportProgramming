#include <stdio.h>

using namespace std;

bool check(int value, int k)
{
  int count = 0;
  while(value != 0)
  {
    int current = value % 10;
    if((current == 7) || (current == 4))
      count++;
    value /= 10;
  }
  return (count <= k);
}

int main()
{
  int n, k;
  scanf("%d %d\n", &n, &k);
  int anwser = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    if(check(tmp, k))
      anwser++;
  }
  printf("%d", anwser);
  return 0;
}

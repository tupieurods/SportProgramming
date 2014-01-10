#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    sum += tmp;
  }
  int anwser = 0;
  n++;
  for(int i = 1; i < 6; i++)
  {
    if(((sum + i) % n) != 1)
      anwser++;
  }
  printf("%d", anwser);
  return 0;
}

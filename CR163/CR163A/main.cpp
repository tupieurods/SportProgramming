#include <stdio.h>

using namespace std;

int main()
{
  int n;
  scanf("%d\n", &n);
  int anwser = 0;
  char last = 'Q';
  for(int i = 0; i < n; i++)
  {
    char current;
    scanf("%c", &current);
    if(current == last)
    {
      anwser++;
    }
    else
    {
      last = current;
    }
  }
  printf("%d\n", anwser);
  return 0;
}

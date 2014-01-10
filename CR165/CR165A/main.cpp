#include <stdio.h>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++)
  {
    int a;
    scanf("%d", &a);
    bool flag = true;
    for(int j = 3; j < 365; j++)
    {
      if(((j - 2) * 180) == (j * a))
      {
        printf("YES\n");
        flag = false;
        break;
      }
    }
    if(flag)
      printf("NO\n");
  }
  return 0;
}

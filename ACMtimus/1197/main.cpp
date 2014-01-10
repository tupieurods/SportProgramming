#include <stdio.h>

int delta[8][2] = 
{
  {2, 1},
  {2, -1},
  {-2, 1},
  {-2, -1},
  {1, 2},
  {1, -2},
  {-1, 2},
  {-1, -2},
};

int main()
{
  int n;
  scanf("%d%*c", &n);
  for(int i = 0; i < n; i++)
  {
    int a, b;
    char c;
    scanf("%c%d%*c", &c, &b);
    a = (int)(c - 'a' + 1);
    int answer = 0;
    for(int j = 0; j < 8; j++)
    {
      int x = a + delta[j][0];
      int y = b + delta[j][1];
      if(x >= 1 && x <= 8 && y >= 1 && y <= 8)
        answer++;
    }
    printf("%d\n", answer);
  }
  return 0;
}